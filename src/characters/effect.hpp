#ifndef EFFECT_HPP_INCLUDED
#define EFFECT_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class Effect : public GameCharacter {
    public:
        Effect(salmon::ActorRef actor, GameScene* scene);
        virtual Effect* create(salmon::ActorRef actor, GameScene* scene) const override {return new Effect(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        static const char* type;
    protected:
        // Add members here
        
    private:
        static const bool good;
};


#endif // EFFECT_HPP_INCLUDED
