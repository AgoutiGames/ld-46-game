#ifndef GARDENER_HPP_INCLUDED
#define GARDENER_HPP_INCLUDED

#include "core/game_character.hpp"

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

        void move(float x, float y) {move_relative(x,y, salmon::Collidees::tile_and_actor,{salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX},true);}

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

    private:
        static const bool good;
};


#endif // GARDENER_HPP_INCLUDED
