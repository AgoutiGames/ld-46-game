#include "characters/gardener.hpp"

#include <iostream>
#include <cmath>

#include "core/game_scene.hpp"
#include "input_cache_ref.hpp"

const char* Gardener::type = "Gardener";
const bool Gardener::good = GameCharacter::register_class<Gardener>(Gardener::type);

Gardener::Gardener(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Gardener::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

    m_gauge = static_cast<WaterMeter*>(m_scene->add_character("Player1CanUI", "Interface"));
    if(m_gauge == nullptr) {
        std::cerr << "Gardener couldn't init his watering gauge!\n";
    }
    else {
        m_gauge->move_absolute(4,32);
    }

    m_score = static_cast<Score*>(m_scene->add_character("Score", "Interface"));
    if(m_score == nullptr) {
        std::cerr << "Gardener couldn't init his score counter!\n";
    }
    else {
        m_score->move_absolute(50,34);
    }

    m_splashing = static_cast<Effect*>(m_scene->add_character("WaterSplash", "Actors"));
    if(m_splashing == nullptr) {
        std::cerr << "Gardener couldn't init his splashing effect!\n";
    }

    m_tick = m_scene->get_audio_manager().get_sound("sounds/tick2.ogg");
    m_tock = m_scene->get_audio_manager().get_sound("sounds/tock2.ogg");

    m_tick.set_volume(0.5);
    m_tock.set_volume(0.5);

    if(!m_tick.good() || !m_tock.good()) {
        std::cerr << "Failed to load gardener walking sound!!";
    }

    m_drip = m_scene->get_audio_manager().get_sound("sounds/drip2.ogg");
    if(!m_drip.good()) {
        std::cerr << "Failed to load gardener dripping sound!!";
    }
    m_drip.set_volume(0.3);

    // Clear data accessed via put
    get_data().clear();
}

void Gardener::update() {
    float delta = m_scene->get_delta_time();

    // Add character logic here
    salmon::InputCacheRef input = m_scene->get_input_cache();

    // Decellerate current speed
    float decellaration_value = m_decellaration_factor * delta;
    if(std::abs(m_x_speed) < decellaration_value) {
        m_x_speed = 0;
    }
    else if(m_x_speed > 0.0) {
        m_x_speed -= decellaration_value;
    }
    else {
        m_x_speed += decellaration_value;
    }


    if(std::abs(m_y_speed) < decellaration_value) {
        m_y_speed = 0;
    }
    else if(m_y_speed > 0.0) {
        m_y_speed -= decellaration_value;
    }
    else {
        m_y_speed += decellaration_value;
    }

    float m_x_direction = 0.0;
    float m_y_direction = 0.0;

    if(input.is_down("w")) {
        animate(salmon::AnimationType::current,salmon::Direction::up);
        //move(0,-1);

        m_y_direction = -1.0;

        m_x_splash_offset = 8.0;
        m_y_splash_offset = -8.0;
    }
    else if(input.is_down("s")) {
        animate(salmon::AnimationType::current,salmon::Direction::down);
        //move(0,1);

        m_y_direction = 1.0;

        m_x_splash_offset = 8.0;
        m_y_splash_offset = 4.0;
    }
    if(input.is_down("a")) {
        animate(salmon::AnimationType::current,salmon::Direction::left);
        //move(-1,0);

        m_x_direction = -1.0;

        m_x_splash_offset = -7.0;
        m_y_splash_offset = -2.0;
    }
    else if(input.is_down("d")) {
        animate(salmon::AnimationType::current,salmon::Direction::right);
        //move(1,0);

        m_x_direction = 1.0;

        m_x_splash_offset = 23.0;
        m_y_splash_offset = -2.0;
    }

    // normalize(m_x_direction,m_y_direction);
    m_x_speed += m_x_direction * (m_acceleration_factor + m_decellaration_factor) * delta;
    m_y_speed += m_y_direction * (m_acceleration_factor + m_decellaration_factor) * delta;
    // Normalize directional speed vector if its over maximum (length of 1.0)

    float len = std::sqrt(m_x_speed * m_x_speed + m_y_speed * m_y_speed);
    if(len > 1.0) {
        normalize(m_x_speed,m_y_speed);
        len = 1.0;
    }

    bool collided = !move(m_max_speed * m_x_speed * delta, 0.0);
    if(collided) {m_x_speed = -0.5 * m_x_speed;}

    collided = !move(0.0, m_max_speed * m_y_speed * delta) || collided;
    if(collided) {m_y_speed = -0.5 * m_y_speed;}

    walk_sound(std::sqrt(m_x_speed * m_x_speed + m_y_speed * m_y_speed));

    /*if(collided) {
        m_x_speed = -m_x_speed;
        m_y_speed = -m_y_speed;
    }*/

    if(input.is_down("space")) {
        if(empty_can(m_drain_rate * delta)) {
            // Update splash effect position
            m_splashing->move_absolute(get_x()+m_x_splash_offset,get_y()+m_y_splash_offset);
            m_splashing->animate();
            if(!m_drip.playing()) {m_drip.play(-1);}
        }
        else {
            m_splashing->set_animation(salmon::AnimationType::current,salmon::Direction::current,0);
        }


    }
    if(input.just_released("space")) {
        m_splashing->set_animation(salmon::AnimationType::current,salmon::Direction::current,0);
        m_drip.halt();
    }

    // Update water can UI
    m_gauge->set_state(m_water_stand);
}

bool Gardener::fill_can(float amount) {
    m_water_stand += amount;
    if(m_water_stand > 0.9999) {
        m_water_stand = 0.9999;
        return false;
    }
    else {
        return true;
    }
}

bool Gardener::empty_can(float amount) {
    m_water_stand -= amount;
    if(m_water_stand < 0.0) {
        m_water_stand = 0.0;
        return false;
    }
    else {
        return true;
    }
}

void Gardener::normalize(float& x, float& y) {
    if(x == 0.0 && y == 0.0) {return;}
    float len = std::sqrt(x*x + y*y);
    x /= len;
    y /= len;
}

void Gardener::walk_sound(float speed) {

    if(speed > 0.0) {
        m_current_step_pause += m_scene->get_delta_time();
    }

    float next_step = (speed * m_min_pause_between_steps + (1.0 - speed) * m_max_pause_between_steps) / 2.0;
    if(m_current_step_pause > next_step) {
        m_current_step_pause -= next_step;
        if(m_is_tick) {
            m_tick.play();
            m_is_tick = false;
        }
        else {
            m_tock.play();
            m_is_tick = true;
        }
    }
}
