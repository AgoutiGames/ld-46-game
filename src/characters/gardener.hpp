#ifndef GARDENER_HPP_INCLUDED
#define GARDENER_HPP_INCLUDED

#include "core/game_character.hpp"

#include "sound_ref.hpp"
#include "characters/water_meter.hpp"
#include "characters/effect.hpp"
#include "characters/score.hpp"

class GameScene;

class Gardener : public GameCharacter {
    public:
        Gardener(salmon::ActorRef actor, GameScene* scene);
        virtual Gardener* create(salmon::ActorRef actor, GameScene* scene) const override {return new Gardener(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        bool move(float x, float y) {return move_relative(x,y, salmon::Collidees::tile_and_actor,{salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX},true);}

        bool fill_can(float amount);
        bool empty_can(float amount);

        bool is_can_empty() {return m_water_stand == 0.0;}

        Score* get_score() {return m_score;}

        static const char* type;
    protected:
        // Add members here
        WaterMeter* m_gauge = nullptr;
        Effect* m_splashing = nullptr;
        Score* m_score = nullptr;

        float m_water_stand = 0.0;

        float m_drain_rate = 0.1; // Depletes can this amount per second

        float m_x_splash_offset = 8.0;
        float m_y_splash_offset = 4.0;


        // Movement physic
        float m_acceleration_factor = 3.5; // This amount of speed is gained per second
        float m_max_speed = 100.0; // Pixel per second

        float m_decellaration_factor = 5.0; // This amount of speed is lost per second

        float m_x_speed = 0.0;
        float m_y_speed = 0.0;

        salmon::SoundRef m_tick;
        salmon::SoundRef m_tock;
        bool m_is_tick = true;

        float m_min_pause_between_steps = 0.4;
        float m_max_pause_between_steps = 2.0;

        float m_current_step_pause = 0.0;

        salmon::SoundRef m_drip;

    private:
        static const bool good;

        void normalize(float& x, float& y);

        void walk_sound(float speed);
};


#endif // GARDENER_HPP_INCLUDED
