#ifndef WATER_PUMP_HPP_INCLUDED
#define WATER_PUMP_HPP_INCLUDED

#include "core/game_character.hpp"

#include "sound_ref.hpp"

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

        void play_sound();

        float m_fill_rate = 0.3; // Fill this amount per second
        salmon::SoundRef m_pump_sound1;
        salmon::SoundRef m_pump_sound2;

        float m_pause_1 = 0.3;
        float m_pause_2 = 0.9;
        bool m_is_pause_1 = true;

        float m_pause_delta = 0.0;
};


#endif // WATER_PUMP_HPP_INCLUDED
