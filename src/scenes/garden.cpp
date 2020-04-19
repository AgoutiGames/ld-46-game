#include "scenes/garden.hpp"

#include <iostream>
#include "core/scene_manager.hpp"

const char* Garden::type = "Garden";
const bool Garden::good = GameScene::register_class<Garden>(Garden::type);

Garden::Garden(salmon::MapRef map, SceneManager* scene_manager) :
    GameScene(map,scene_manager) {}

void Garden::init() {
    // Initializes all characters in scene
    GameScene::init();
    // Setup member vars here | example: put(m_speed, "m_speed");
    m_scene_manager->set_game_resolution(400,400);
    m_scene_manager->set_window_size(800,800);

    m_sun_meter = static_cast<WaterMeter*>(get_character_by_name("SunMeter"));
    if(m_sun_meter == nullptr) {
        std::cerr << "Severe error! Map can't find the SunMeter!!!\n";
    }
    else {
        m_sun_meter->set_state(0.9999);
    }

    m_timer = m_time_limit;

    // Clear data accessed via put
    get_data().clear();
}

void Garden::update() {
    // Add scene logic here

    // Calls update on all characters in scene
    m_timer -= get_delta_time();
    if(m_timer < 0.0) {m_timer = 0.0;}
    m_sun_meter->set_state(m_timer/m_time_limit);
    if(m_timer > 0.0) {
        GameScene::update();
    }
}
