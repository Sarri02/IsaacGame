#include "AchievementsDisplay.h"

bool AchievementsDisplay::update(int value,int control) {
    {
        this->value = value;

        return (value>=control and (++time)<350);
    }

}

AchievementsDisplay::AchievementsDisplay(Isaac * isaac,Texture * t) {

    time = 0;
    subject = isaac;
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

