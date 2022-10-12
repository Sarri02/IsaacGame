
#include "Rock.h"

Rock::Rock(Vector2f position) {

    if(rand()%20==1){
        this->isSigned= true;
        this->texture.loadFromFile("./Texture/SignedRock.png");
    }
    else{
        this->isSigned= false;
        this->texture.loadFromFile("./Texture/Rock.png");
    }
    setSize(Vector2f(50,50));
    setTexture(&this->texture);
    setPosition(position);
}

Rock::~Rock() = default;
