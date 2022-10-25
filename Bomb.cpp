#include "Bomb.h"

Bomb::Bomb(Vector2f position) {

    this->time=100;

    this->texture.loadFromFile("./Texture/Bomb.png");
    this->bomb.setSize(Vector2f(60,60));
    this->bomb.setPosition(position);
    this->explosion = this->bomb;
    this->bomb.setTexture(&this->texture);
    this->explosion.setFillColor(Color::Transparent);
    explosion.setSize(Vector2f(160,160));
    explosion.setPosition(this->bomb.getPosition().x-50,this->bomb.getPosition().y-50);

}

void Bomb::DrawBomb(RenderWindow &window) {

    window.draw(this->explosion);
    window.draw(this->bomb);

}

bool Bomb::updateBomb() {
    if(this->time>0){
        if(this->time%20>10)
            this->bomb.setSize(Vector2f(65,65));
        else
            this->bomb.setSize(Vector2f(60,60));
        this->time--;
        return true;
    }
    return false;
}

Bomb::~Bomb() = default;

