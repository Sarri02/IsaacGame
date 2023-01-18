#ifndef FLOOR_CPP_ACHIEVEMENTSDISPLAY_H
#define FLOOR_CPP_ACHIEVEMENTSDISPLAY_H

#include "Observer.h"
#include "Character.h"

class AchievementsDisplay : public Observer {
private:
    Character *subject;
    int value;
    int control;
    int time;
    RectangleShape achievements;


public:
    AchievementsDisplay (Character * isaac, Texture * t, int control);

    ~AchievementsDisplay() override;

    void update(int value) override;

    bool isDrawable();

    void drawAchievements(RenderWindow & window);


};
#endif
