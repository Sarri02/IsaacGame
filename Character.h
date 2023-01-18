#ifndef ISAAC_CHARACTER_H
#define ISAAC_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Observer.h"


using namespace std;

using namespace sf;

class Character {

protected:

    //Variables
    float Life;
    float Speed;

    //Private Functions

public:
    virtual ~Character();


    //Public Functions
    void setLife(float Life);
    void setSpeed(float Speed);
    float getLife();
    float getSpeed();
    void TakeDamage(float damage);

    virtual void Draw(RenderWindow &window) = 0;


    //Observer list
    list< Observer* > observers;

    virtual void registerObserver(Observer* obs) {
        observers.push_back(obs);    }
    virtual void removeObserver(Observer* obs) {
        observers.remove(obs);    }

};

#endif