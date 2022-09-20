#include "Bullet.h"
#include <iostream>

Bullet::Bullet(Texture *texture, float xPos, float yPos, float xDir, float yDir, float speed) {
    //Texture
    this->bulletFigure.setTexture(*texture);
    //Position
    this->bulletFigure.setPosition(xPos, yPos);
    this->direction.x = xDir;
    this->direction.y = yDir;

    this->speed = speed;
}



//Update
bool Bullet::updateBullet() {
    if(MoveIsPossible(this->direction.x, this->direction.y)){
        this->bulletFigure.move(this->speed * this->direction);
        return true;
    }
    else
        return false;
}

//Render
void Bullet::drawBullet(RenderWindow & window) {
    window.draw(this->bulletFigure);

}

bool Bullet::MoveIsPossible(float dirX, float dirY) {
    Vector2f pos=this->bulletFigure.getPosition();
    float x = pos.x;
    float y = pos.y;
    x+=(dirX*this->speed);
    y+=(dirY*this->speed);
    return (x<880 && x>40 && y<615 && y>215);
}

Bullet::~Bullet() {

}
