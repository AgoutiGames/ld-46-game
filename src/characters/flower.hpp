#ifndef FLOWER_HPP_INCLUDED
#define FLOWER_HPP_INCLUDED

#include "core/game_character.hpp"

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
        
    private:
        static const bool good;
};


#endif // FLOWER_HPP_INCLUDED
