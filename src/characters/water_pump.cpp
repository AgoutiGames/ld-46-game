#include "characters/water_pump.hpp"

#include <iostream>

#include "input_cache_ref.hpp"
#include "core/game_scene.hpp"
#include "characters/gardener.hpp"

const char* WaterPump::type = "WaterPump";
const bool WaterPump::good = GameCharacter::register_class<WaterPump>(WaterPump::type);

WaterPump::WaterPump(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void WaterPump::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

    m_pump_sound1 = m_scene->get_audio_manager().get_sound("sounds/p1.ogg");
    m_pump_sound2 = m_scene->get_audio_manager().get_sound("sounds/p2.ogg");
    if(!m_pump_sound2.good() || !m_pump_sound1.good()) {
        std::cerr << "Failed to load pump sound!!";
    }
    m_pump_sound1.set_volume(0.5);
    m_pump_sound2.set_volume(0.5);

    // Clear data accessed via put
    get_data().clear();
}

void WaterPump::update() {
    // Add character logic here
    // salmon::InputCacheRef input = m_scene->get_input_cache();
    std::vector<salmon::CollisionRef> collisions = get_collisions();

    bool pump = false;
    Gardener* player = nullptr;

    for(salmon::CollisionRef c : collisions) {
        if(c.my_hitbox() == "FILL" && c.other_hitbox() == "FILL") {
            pump = true;
            player = static_cast<Gardener*>(m_scene->get_character_by_id(c.get_actor_id()));
        }
    }
    clear_collisions();

    if(pump) {
        player->fill_can(m_fill_rate * m_scene->get_delta_time());
        animate();
        play_sound();
    }
    else {
        set_animation(salmon::AnimationType::current, salmon::Direction::current,0);
        // Reset sound
        m_pause_delta = 0.0;
        m_is_pause_1 = true;
    }
}

void WaterPump::play_sound() {
    float delta = m_scene->get_delta_time();

    m_pause_delta += delta;
    if(m_is_pause_1) {
        if(m_pause_delta > m_pause_1) {
            m_pause_delta -= m_pause_1;
            m_is_pause_1 = false;
            m_pump_sound1.play();
        }
    }
    else {
        if(m_pause_delta > m_pause_2) {
            m_pause_delta -= m_pause_2;
            m_is_pause_1 = true;
            m_pump_sound2.play();
        }
    }
}
