#ifndef SCORE_HPP_INCLUDED
#define SCORE_HPP_INCLUDED

#include "core/game_character.hpp"
#include "text_ref.hpp"

class GameScene;

class Score : public GameCharacter {
    public:
        Score(salmon::ActorRef actor, GameScene* scene);
        virtual Score* create(salmon::ActorRef actor, GameScene* scene) const override {return new Score(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        static const char* type;

        void add_points(int amount);
        int get_points() const {return m_points;}

    protected:
        // Add members here
        int m_points = 0;

        salmon::TextRef m_score_text = nullptr;

    private:
        static const bool good;
};


#endif // SCORE_HPP_INCLUDED
