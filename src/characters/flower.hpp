#ifndef FLOWER_HPP_INCLUDED
#define FLOWER_HPP_INCLUDED

#include "core/game_character.hpp"
#include "characters/water_meter.hpp"

class GameScene;

class Flower : public GameCharacter {
    public:
        Flower(salmon::ActorRef actor, GameScene* scene);
        virtual Flower* create(salmon::ActorRef actor, GameScene* scene) const override {return new Flower(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        static const char* type;
    protected:
        // Add members here
        WaterMeter* m_gauge;

    private:
        static const bool good;

        float m_water_stand = 0.9999;
        float m_water_loss = 0.02; // Per second

        float m_fill_rate = 0.75; // Fills flower pot this amount per second

        float m_seconds_per_point = 5; // All five seconds one point is granted
        float m_seconds = 0.0;

        int m_player_index = 0;

        bool m_dead = false;
};


#endif // FLOWER_HPP_INCLUDED
