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
    if(!m_end) {
        m_timer -= get_delta_time();
        if(m_timer < 0.0) {
            m_timer = 0.0;
            m_end = true;

            // Setup End Game Screen!
            unhide_layer("GameOver");

            salmon::TextRef::Attributes a;
            a.bold = true;
            a.color = {155,50,50};
            a.font_family = "OpenSans";
            // a.underline = true;
            a.pixel_size = 35;
            add_text("EndScreen", "Text",90,170, "GAME OVER", a);

            a.bold = false;
            a.color = {0,0,0};
            a.pixel_size = 10;
            add_text("Button Notice", "Text", 135, 208, "Press Return to start again!", a);

        }

        m_sun_meter->set_state(m_timer/m_time_limit);
        GameScene::update();
    }
    else {
        if(get_input_cache().just_pressed("Return")) {
            m_scene_manager->next_scene("menu.tmx");
        }
    }
}
