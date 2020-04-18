#include "characters/gardener.hpp"

#include "core/game_scene.hpp"
#include "input_cache_ref.hpp"

const char* Gardener::type = "Gardener";
const bool Gardener::good = GameCharacter::register_class<Gardener>(Gardener::type);

Gardener::Gardener(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Gardener::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

    // Clear data accessed via put
    get_data().clear();
}

void Gardener::update() {
    // Add character logic here
    salmon::InputCacheRef input = m_scene->get_input_cache();

    if(input.is_down("w")) {
        animate(salmon::AnimationType::current,salmon::Direction::up);
        move(0,-1);
    }
    else if(input.is_down("s")) {
        animate(salmon::AnimationType::current,salmon::Direction::down);
        move(0,1);
    }
    if(input.is_down("a")) {
        animate(salmon::AnimationType::current,salmon::Direction::left);
        move(-1,0);
    }
    else if(input.is_down("d")) {
        animate(salmon::AnimationType::current,salmon::Direction::right);
        move(1,0);
    }
}
