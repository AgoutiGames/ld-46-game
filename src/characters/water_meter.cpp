#include "characters/water_meter.hpp"

const char* WaterMeter::type = "WaterMeter";
const bool WaterMeter::good = GameCharacter::register_class<WaterMeter>(WaterMeter::type);

WaterMeter::WaterMeter(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void WaterMeter::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

    // Clear data accessed via put
    get_data().clear();
}

void WaterMeter::update() {
    // Add character logic here

}

void WaterMeter::set_state(float amount) {
    if(amount > 0.0 && amount <= 1.0) {
        int frame = amount * (get_anim_frame_count()-1) + 1;
        set_animation(salmon::AnimationType::current, salmon::Direction::current, frame);
    }
    else if(amount == 0.0) {
        set_animation(salmon::AnimationType::current, salmon::Direction::current, 0);
    }
}
