#include "Bullet.h"

Bullet::Bullet(Texture *texture, float xPos, float yPos, float xDir, float yDir, float speed, float range) {
    //Texture
    this->bulletFigure.setTexture(texture);
    this->bulletFigure.setSize(Vector2f(30,30));
    //Position
    this->bulletFigure.setPosition(xPos, yPos);
    this->direction.x = xDir;
    this->direction.y = yDir;

    this->speed = speed;
    this->range = range;
}



//Update
bool Bullet::updateBullet() {
    if(MoveIsPossible(this->direction.x, this->direction.y) && this->range>0){
        this->bulletFigure.move(this->speed * this->direction);
        this->range -= this->speed;
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
    return (x<905 && x>40 && y<650 && y>215);
}

Bullet::~Bullet() {

}
