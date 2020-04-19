#include "characters/gardener.hpp"

#include <iostream>

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

    // Clear data accessed via put
    get_data().clear();
}

void Gardener::update() {
    float delta = m_scene->get_delta_time();

    // Add character logic here
    salmon::InputCacheRef input = m_scene->get_input_cache();

    if(input.is_down("w")) {
        animate(salmon::AnimationType::current,salmon::Direction::up);
        move(0,-1);

        m_x_splash_offset = 8.0;
        m_y_splash_offset = -8.0;
    }
    else if(input.is_down("s")) {
        animate(salmon::AnimationType::current,salmon::Direction::down);
        move(0,1);

        m_x_splash_offset = 8.0;
        m_y_splash_offset = 4.0;
    }
    if(input.is_down("a")) {
        animate(salmon::AnimationType::current,salmon::Direction::left);
        move(-1,0);

        m_x_splash_offset = -7.0;
        m_y_splash_offset = -2.0;
    }
    else if(input.is_down("d")) {
        animate(salmon::AnimationType::current,salmon::Direction::right);
        move(1,0);

        m_x_splash_offset = 23.0;
        m_y_splash_offset = -2.0;
    }

    if(input.is_down("space")) {
        if(empty_can(m_drain_rate * delta)) {
            // Update splash effect position
            m_splashing->move_absolute(get_x()+m_x_splash_offset,get_y()+m_y_splash_offset);
            m_splashing->animate();
        }
        else {
            m_splashing->set_animation(salmon::AnimationType::current,salmon::Direction::current,0);
        }


    }
    if(input.just_released("space")) {
        m_splashing->set_animation(salmon::AnimationType::current,salmon::Direction::current,0);
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
