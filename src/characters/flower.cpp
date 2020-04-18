#include "characters/flower.hpp"

const char* Flower::type = "Flower";
const bool Flower::good = GameCharacter::register_class<Flower>(Flower::type);

Flower::Flower(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Flower::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    set_animation(salmon::AnimationType::current, salmon::Direction::current, 5);

    // Clear data accessed via put
    get_data().clear();
}

void Flower::update() {
    // Add character logic here
    animate(salmon::AnimationType::current,salmon::Direction::current,0.25);
}
