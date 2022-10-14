#ifndef ISAAC_DOOR_H
#define ISAAC_DOOR_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Door: public RectangleShape{
private:

    Texture texture;
    unsigned short int direction;

public:
    Door(unsigned short int direction);
    virtual ~Door();

};

#endif