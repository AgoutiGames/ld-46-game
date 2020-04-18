#include "characters/water_pump.hpp"

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
    animate();

}
