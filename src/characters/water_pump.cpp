#include "characters/water_pump.hpp"

#include "input_cache_ref.hpp"
#include "core/game_scene.hpp"
#include "characters/gardener.hpp"

const char* WaterPump::type = "WaterPump";
const bool WaterPump::good = GameCharacter::register_class<WaterPump>(WaterPump::type);

WaterPump::WaterPump(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void WaterPump::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

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
    }
    else {
        set_animation(salmon::AnimationType::current, salmon::Direction::current,0);
    }
}
