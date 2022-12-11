#include "Door.h"

Door::Door(unsigned short direction) {
    this->direction=direction;
    this->texture.loadFromFile("./Texture/door.png");
    setTexture(&this->texture);
    switch (this->direction) {
        case 0:
            //sopra
            setSize(Vector2f(90,40));
            setPosition(480-getSize().x/2,184);
            break;
        case 1:
            //destra
            setSize(Vector2f(40,90));
            setPosition(915,380);
            break;
        case 2:
            //sotto
            setSize(Vector2f(90,40));
            setPosition(480-getSize().x/2,676);
            break;
        case 3:
            //sinistra
            setSize(Vector2f(40,90));
            setPosition(10,380);
            break;
        default:
            break;
    }
}


Door::~Door() = default;

