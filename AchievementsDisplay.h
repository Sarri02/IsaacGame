#ifndef FLOOR_CPP_ACHIEVEMENTSDISPLAY_H
#define FLOOR_CPP_ACHIEVEMENTSDISPLAY_H

#include "Isaac.h"

class AchievementsDisplay : public Observer {
private:
    Isaac *subject;
    int value;
    int time;
    RectangleShape achievements;


public:
    AchievementsDisplay(Isaac *isaact, Texture * t);

    ~AchievementsDisplay() override;

    bool update(int value,int control) override;

    void drawAchievements(RenderWindow & window);


};
#endif
