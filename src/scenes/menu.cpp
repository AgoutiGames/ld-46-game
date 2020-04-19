#include "scenes/menu.hpp"

#include "core/scene_manager.hpp"

#include <iostream>

const char* Menu::type = "Menu";
const bool Menu::good = GameScene::register_class<Menu>(Menu::type);

Menu::Menu(salmon::MapRef map, SceneManager* scene_manager) :
    GameScene(map,scene_manager) {}

void Menu::init() {
    m_scene_manager->set_game_resolution(400,400);
    m_scene_manager->set_fullscreen(false);
    m_scene_manager->set_window_size(800,800);

    m_bg_music = get_audio_manager().get_music("music/gardening_music.ogg");
    if(!m_bg_music.good()) {
        std::cerr << "Failed to load music!";
    }
    m_bg_music.set_volume(0.25);
    if(!m_bg_music.playing()) {
        m_bg_music.play();
    }

    // Preload whole data folder
    // m_scene_manager->add_preload_directory("");
    // m_scene_manager->preload(50);
    // Initializes all characters in scene
    GameScene::init();
    // Setup member vars here | example: put(m_speed, "m_speed");

    if(salmon::WEB_BUILD) {
        remove_character(get_character_by_name("QuitButton"));
    }

    // Clear data accessed via put
    get_data().clear();
}

void Menu::update() {
    // Add scene logic here
    salmon::InputCacheRef input = get_input_cache();
    if(input.just_pressed("Escape")) {
        m_scene_manager->shutdown();
    }
    if(m_instructions_open && (input.get_mouse_state().left.pressed || input.just_pressed("Return"))) {
        hide_layer("Instructions1");
        hide_layer("Instructions2");
        m_instructions_open = false;
    }

    // Calls update on all characters in scene
    GameScene::update();
}

void Menu::button_pressed(std::string id) {
    if(!m_instructions_open) {
        if(id == "Quit") {
            m_scene_manager->shutdown();
        }
        else if(id == "Start") {
            // Load next scene file
            m_scene_manager->next_scene("garden1.tmx");
        }
        else if(id == "HowTo") {
            unhide_layer("Instructions1");
            unhide_layer("Instructions2");
            m_instructions_open = true;
        }
        else {
            std::cerr << "Button type: " << id << " is unrecognized!\n";
        }
    }
}
