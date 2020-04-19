#include "characters/effect.hpp"

const char* Effect::type = "Effect";
const bool Effect::good = GameCharacter::register_class<Effect>(Effect::type);

Effect::Effect(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Effect::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    
    // Clear data accessed via put
    get_data().clear();
}

void Effect::update() {
    // Add character logic here
    
}
