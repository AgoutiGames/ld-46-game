#ifndef GARDENER_HPP_INCLUDED
#define GARDENER_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class Gardener : public GameCharacter {
    public:
        Gardener(salmon::ActorRef actor, GameScene* scene);
        virtual Gardener* create(salmon::ActorRef actor, GameScene* scene) const override {return new Gardener(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        void move(float x, float y) {move_relative(x,y, salmon::Collidees::tile_and_actor,{salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX},true);}

        static const char* type;
    protected:
        // Add members here

    private:
        static const bool good;
};


#endif // GARDENER_HPP_INCLUDED
