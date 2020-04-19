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

    put(m_player_index, "m_player_index");

    if(m_player_index == 0) {
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
    }

    else if(m_player_index == 1) {
        m_gauge = static_cast<WaterMeter*>(m_scene->add_character("Player1CanUI", "Interface"));
        if(m_gauge == nullptr) {
            std::cerr << "Gardener couldn't init his watering gauge!\n";
        }
        else {
            m_gauge->move_absolute(364,32);
        }

        m_score = static_cast<Score*>(m_scene->add_character("Score", "Interface"));
        if(m_score == nullptr) {
            std::cerr << "Gardener couldn't init his score counter!\n";
        }
        else {
            m_score->move_absolute(318,34);
        }
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

    m_shove_sound = m_scene->get_audio_manager().get_sound("sounds/shove.ogg");
    if(!m_shove_sound.good()) {
        std::cerr << "Failed to load gardener shoving sound!!";
    }

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

    std::string up_key;
    std::string down_key;
    std::string left_key;
    std::string right_key;
    std::string water_key;
    std::string shove_key;

    if(m_player_index == 0) {
        up_key = "w";
        down_key = "s";
        left_key = "a";
        right_key = "d";
        water_key = "Space";
        shove_key = "Left Ctrl";
    }
    else if (m_player_index == 1) {
        up_key = "Up";
        down_key = "Down";
        left_key = "Left";
        right_key = "Right";
        water_key = "Right Ctrl";
        shove_key = "Keypad 0";
    }
    bool has_gamepad = false;
    salmon::GamepadState gamepad;
    if(input.get_gamepad_count() > static_cast<unsigned>(m_player_index)) {
        has_gamepad = true;
        gamepad = input.get_gamepad(m_player_index);
    }

    if(input.is_down(up_key) || (has_gamepad && (gamepad.button.up.down || gamepad.axis.left_y < 0.0)) ) {
        animate(salmon::AnimationType::current,salmon::Direction::up);
        //move(0,-1);

        m_y_direction = -1.0;

        m_x_splash_offset = 8.0;
        m_y_splash_offset = -8.0;
    }
    else if(input.is_down(down_key) || (has_gamepad && (gamepad.button.down.down || gamepad.axis.left_y > 0.0)) ) {
        animate(salmon::AnimationType::current,salmon::Direction::down);
        //move(0,1);

        m_y_direction = 1.0;

        m_x_splash_offset = 8.0;
        m_y_splash_offset = 4.0;
    }
    if(input.is_down(left_key) || (has_gamepad && (gamepad.button.left.down || gamepad.axis.left_x < 0.0)) ) {
        animate(salmon::AnimationType::current,salmon::Direction::left);
        //move(-1,0);

        m_x_direction = -1.0;

        m_x_splash_offset = -7.0;
        m_y_splash_offset = -2.0;
    }
    else if(input.is_down(right_key) || (has_gamepad && (gamepad.button.right.down || gamepad.axis.left_x > 0.0)) ) {
        animate(salmon::AnimationType::current,salmon::Direction::right);
        //move(1,0);

        m_x_direction = 1.0;

        m_x_splash_offset = 23.0;
        m_y_splash_offset = -2.0;
    }

    if(m_is_shoved) {
        m_shove_cooldown += delta;
        if(m_shove_cooldown >= m_shove_duration) {
            m_is_shoved = false;
        }
        else {
            m_x_direction += m_x_shove;
            m_y_direction += m_y_shove;
        }
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


    for(salmon::CollisionRef c : get_collisions()) {
        if(c.my_hitbox() == "SHOVE" && c.other_hitbox() == "SHOVE") {
            if(input.is_down(shove_key) || (has_gamepad && gamepad.button.b.down)) {
                static_cast<Gardener*>(m_scene->get_character_by_id(c.get_actor_id()))->get_shoved(this);
            }
        }
    }

    clear_collisions();
    /*if(collided) {
        m_x_speed = -m_x_speed;
        m_y_speed = -m_y_speed;
    }*/

    if(input.is_down(water_key) || (has_gamepad && gamepad.button.a.down) ) {
        if(empty_can(m_drain_rate * delta)) {
            // Update splash effect position
            m_splashing->move_absolute(get_x()+m_x_splash_offset,get_y()+m_y_splash_offset);
            m_splashing->animate();
            if(!m_drip.playing()) {m_drip.play(-1);}
            m_is_watering = true;
        }
        else {
            m_splashing->set_animation(salmon::AnimationType::current,salmon::Direction::current,0);
            m_is_watering = false;
        }


    }
    if(input.just_released(water_key) || (has_gamepad && gamepad.button.a.released) ) {
        m_splashing->set_animation(salmon::AnimationType::current,salmon::Direction::current,0);
        m_drip.halt();
        m_is_watering = false;
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

void Gardener::get_shoved(Gardener* other) {
    if(m_is_shoved) {return;}

    m_shove_sound.play();

    m_is_shoved = true;
    float x_delta = other->get_x() - get_x();
    float y_delta = other->get_y() - get_y();

    normalize(x_delta,y_delta);
    m_x_shove = -x_delta;
    m_y_shove = -y_delta;

    /*
    // Get shoved horizontally
    if(std::abs(x_delta) > std::abs(y_delta)) {
        // Get shoved to the left
        if(x_delta > 0.0) {
            m_x_shove = -1.0;
            m_y_shove = 0.0;
        }
        // Get shoved to the right
        else {
            m_x_shove = 1.0;
            m_y_shove = 0.0;
        }
    }
    // Get shoved vertically
    else {
        // Get shoved up
        if(y_delta > 0.0) {
            m_x_shove = 0.0;
            m_y_shove = -1.0;
        }
        // Get shoved down
        else {
            m_x_shove = 0.0;
            m_y_shove = 1.0;
        }
    }*/

    m_shove_cooldown = 0.0;
}
