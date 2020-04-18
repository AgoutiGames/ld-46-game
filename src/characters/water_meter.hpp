#ifndef WATER_METER_HPP_INCLUDED
#define WATER_METER_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class WaterMeter : public GameCharacter {
    public:
        WaterMeter(salmon::ActorRef actor, GameScene* scene);
        virtual WaterMeter* create(salmon::ActorRef actor, GameScene* scene) const override {return new WaterMeter(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        void set_state(float amount);

        static const char* type;
    protected:
        // Add members here

    private:
        static const bool good;
};


#endif // WATER_METER_HPP_INCLUDED
