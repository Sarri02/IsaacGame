#include "AchievementsDisplay.h"

void AchievementsDisplay::update(int value) {
    {

        this->value = value;

    }

}

AchievementsDisplay::AchievementsDisplay(Character * isaac,Texture * t, int control) {

    time = 0;
    subject = isaac;
    this->value=0;
    this->control=control;

    //Figure
    achievements.setTexture(t);
    achievements.setSize(Vector2f (120,80));
    achievements.setPosition(830,625);

    subject->registerObserver( this );
    }

AchievementsDisplay::~AchievementsDisplay() {
    subject->removeObserver( this );
}

void AchievementsDisplay::drawAchievements(RenderWindow &window) {

    window.draw(achievements);

}

bool AchievementsDisplay::isDrawable() {
    //Timer
    return (this->value>=this->control and (++time)<350);
}

