#ifndef GARDEN_HPP_INCLUDED
#define GARDEN_HPP_INCLUDED

#include "core/game_scene.hpp"

class SceneManager;

class Garden : public GameScene {
    public:
        Garden(salmon::MapRef map, SceneManager* scene_manager);
        Garden* create(salmon::MapRef map, SceneManager* scene_manager) const override {return new Garden(map,scene_manager);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        static const char* type;
    protected:
        // Add members here
        
    private:
        static const bool good;
};

#endif // GARDEN_HPP_INCLUDED
