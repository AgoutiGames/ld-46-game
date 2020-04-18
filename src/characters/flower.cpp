#include "characters/flower.hpp"

#include <iostream>

#include "core/game_scene.hpp"

const char* Flower::type = "Flower";
const bool Flower::good = GameCharacter::register_class<Flower>(Flower::type);

Flower::Flower(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Flower::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    set_animation(salmon::AnimationType::current, salmon::Direction::current, 5);

    m_gauge = static_cast<WaterMeter*>(m_scene->add_character("DefaultWaterMeter","Interface"));
    if(m_gauge == nullptr) {
        std::cerr << "Failed generating the gauge for a flower!!\n";
    }
    else {
        m_gauge->move_absolute(get_x() + 1,get_y()+14);
    }

    // Clear data accessed via put
    get_data().clear();
}

void Flower::update() {
    // Add character logic here
    float delta = m_scene->get_delta_time();

    if(m_water_stand > 0.0) {
        m_water_stand -= m_water_loss * delta;
        int frame = m_water_stand * (get_anim_frame_count()-1) + 1;
        set_animation(salmon::AnimationType::current, salmon::Direction::current, frame);
        m_gauge->set_state(m_water_stand);
    }
    else {
        set_animation(salmon::AnimationType::current, salmon::Direction::current,0);
        m_gauge->set_state(0.0);
    }
}
