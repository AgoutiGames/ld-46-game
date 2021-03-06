#include "characters/flower.hpp"

#include <iostream>
#include <sstream>

#include "core/game_scene.hpp"
#include "characters/gardener.hpp"

const char* Flower::type = "Flower";
const bool Flower::good = GameCharacter::register_class<Flower>(Flower::type);

Flower::Flower(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Flower::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

    m_gauge = static_cast<WaterMeter*>(m_scene->add_character("DefaultWaterMeter","Interface"));
    if(m_gauge == nullptr) {
        std::cerr << "Failed generating the gauge for a flower!!\n";
    }
    else {
        m_gauge->move_absolute(get_x() + 1,get_y()+14);
    }

    put(m_player_index, "m_player_index");

    std::string anim;
    if(m_player_index == 0) {
        anim = "GROW0";
    }
    else {
        anim = "GROW1";
    }

    set_animation(anim, salmon::Direction::current, 5);

    // Clear data accessed via put
    get_data().clear();
}

void Flower::update() {
    // Add character logic here
    float delta = m_scene->get_delta_time();

    if(!m_dead) {
        for(salmon::CollisionRef c : get_collisions()) {
            if(c.my_hitbox() == "WATER" && c.other_hitbox() == "WATER") {
                Gardener* g = static_cast<Gardener*>(m_scene->get_character_by_id(c.get_actor_id()));
                if(g == nullptr) {
                    std::cerr << "BIG ERROR! FLOWER CAN'T FIND GARDENER!!\n";
                }
                else if (g->m_is_watering) {
                    m_player_index = g->m_player_index;
                    m_water_stand += m_fill_rate * delta;
                    if(m_water_stand > 0.9999) {m_water_stand = 0.9999;}
                }
            }
        }
    }

    clear_collisions();

    std::stringstream player_name;
    player_name << "Player" << (m_player_index + 1);
    std::string anim;
    if(m_player_index == 0) {
        anim = "GROW0";
    }
    else {
        anim = "GROW1";
    }

    if(!m_dead) {
        if(m_water_stand > 0.0) {
            m_water_stand -= m_water_loss * delta;
            int frame = m_water_stand * (get_anim_frame_count()-1) + 1;
            set_animation(anim, salmon::Direction::current, frame);
            m_gauge->set_state(m_water_stand);

            m_seconds += delta;
            if(m_seconds > m_seconds_per_point) {
                m_seconds -= m_seconds_per_point;
                static_cast<Gardener*>(m_scene->get_character_by_name(player_name.str()))->get_score()->add_points(1);
            }
        }
        else {
            set_animation(anim, salmon::Direction::current,0);
            m_gauge->set_state(0.0);
            m_dead = true;

            // Remove ten points if plant is dead!
            static_cast<Gardener*>(m_scene->get_character_by_name(player_name.str()))->get_score()->add_points(-10);
        }
    }



}
