#ifndef WATER_PUMP_HPP_INCLUDED
#define WATER_PUMP_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class WaterPump : public GameCharacter {
    public:
        WaterPump(salmon::ActorRef actor, GameScene* scene);
        virtual WaterPump* create(salmon::ActorRef actor, GameScene* scene) const override {return new WaterPump(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        static const char* type;
    protected:
        // Add members here

    private:
        static const bool good;

        float m_fill_rate = 0.3; // Fill this amount per second
};


#endif // WATER_PUMP_HPP_INCLUDED
