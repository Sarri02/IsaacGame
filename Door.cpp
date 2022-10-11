#include "Door.h"

Door::Door(unsigned short direction) {
    this->direction=direction;
    this->texture.loadFromFile("./Texture/door.png");
    setTexture(&this->texture);
    switch (this->direction) {
        case 0:
            //sopra
            setSize(Vector2f(90,40));
            setPosition(480-getSize().x/2,180);
            break;
        case 1:
            //destra
            setSize(Vector2f(40,90));
            setPosition(915,380);
            break;
        case 2:
            //sotto
            setSize(Vector2f(90,40));
            setPosition(480-getSize().x/2,680);
            break;
        case 3:
            //sinistra
            setSize(Vector2f(40,90));
            setPosition(6,380);
            break;
        default:
            break;
    }

}

bool Door::CheckCollision(RectangleShape isaac) {

    bool collisionX = isaac.getPosition().x + isaac.getSize().x >= getPosition().x &&
                      getPosition().x + getSize().x >= isaac.getPosition().x;
    bool collisionY = isaac.getPosition().y + isaac.getSize().y >= getPosition().y &&
                      getPosition().y + getSize().y >= isaac.getPosition().y;
    return collisionX && collisionY;

}


Door::~Door() = default;

