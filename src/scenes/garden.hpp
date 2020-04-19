#ifndef GARDEN_HPP_INCLUDED
#define GARDEN_HPP_INCLUDED

#include "core/game_scene.hpp"
#include "characters/water_meter.hpp"

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
        WaterMeter* m_sun_meter;

        float m_time_limit = 90; // Seconds
        float m_timer;


    private:
        static const bool good;
};

#endif // GARDEN_HPP_INCLUDED
