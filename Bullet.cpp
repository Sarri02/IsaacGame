#include "Bullet.h"
#include <iostream>

Bullet::Bullet(Texture *texture, float xPos, float yPos, float xDir, float yDir, float speed) {
    //Texture
    this->bulletFigure.setTexture(texture);
    //Position
    this->bulletFigure.setPosition(xPos, yPos);
    this->direction.x = xDir;
    this->direction.y = yDir;

    this->speed = speed;
}

Bullet::~Bullet()
= default;

//Update
void Bullet::updateBullet() {
    this->bulletFigure.move(this->speed * this->direction);
}

//Render
void Bullet::drawBullet(RenderWindow & window) {
    window.draw(this->bulletFigure);

}
