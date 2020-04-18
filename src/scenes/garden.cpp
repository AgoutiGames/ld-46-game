#include "scenes/garden.hpp"

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

    // Clear data accessed via put
    get_data().clear();
}

void Garden::update() {
    // Add scene logic here

    // Calls update on all characters in scene
    GameScene::update();
}
