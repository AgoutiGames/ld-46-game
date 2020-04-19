#include "characters/score.hpp"

#include <sstream>
#include <iomanip>

#include "core/game_scene.hpp"


const char* Score::type = "Score";
const bool Score::good = GameCharacter::register_class<Score>(Score::type);

Score::Score(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Score::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

    salmon::TextRef::Attributes attributes;
    attributes.pixel_size = 14;
    attributes.bold = true;
    attributes.font_family = "OpenSans";

    m_score_text = m_scene->add_text("ScoreText", "Text", get_x()+2, get_y()-26,"000", attributes);
    // Clear data accessed via put
    get_data().clear();
}

void Score::update() {
    // Add character logic here
}

void Score::add_points(int amount) {
    m_points += amount;
    m_points %= 1000;
    std::stringstream text;
    text << std::setfill('0') << std::setw(3) << m_points;
    m_score_text.set_text(text.str());
    m_score_text.apply();
}
