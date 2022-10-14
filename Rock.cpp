#include <iostream>
#include "Rock.h"

Rock::Rock(Vector2f position) {

    if(rand()%80==0){
        this->isSigned= true;
        this->texture.loadFromFile("./Texture/SignedRock.png");
    }
    else{
        this->isSigned= false;
        this->texture.loadFromFile("./Texture/Rock.png");
    }
    this->rock.setSize(Vector2f(75,75));
    this->rock.setTexture(&this->texture);
    this->rock.setPosition(position);
}

void Rock::DrawRock(RenderWindow & window) {

    window.draw(this->rock);

}

Rock::~Rock() {
    if(this->isSigned)
        //TODO droppa l'oggetto
        std::cout<<"OGGETTO";

}

