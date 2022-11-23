#ifndef ISAAC_CHARACTER_H
#define ISAAC_CHARACTER_H

#include <SFML/Graphics.hpp>


using namespace sf;

class Character{

protected:

    //Variables
    float Life;
    float Speed;

    //Private Functions

public:


    virtual ~Character();
    //TODO bool CanFly;
    //TODO int MoveSet;

    //Public Functions
    void setLife(float Life);
    void setSpeed(float Speed);
    float getLife();
    float getSpeed();
    void TakeDamage(float damage);

    virtual void Draw(RenderWindow &window) = 0;

};

#endif