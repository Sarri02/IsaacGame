#include "Isaac.h"
#include <iostream>



//Constructor
Isaac::Isaac(Vector2f position) {

    this->InitIsaac();
    this->InitIsaacFigure(position);


}

Isaac::~Isaac() = default;

//Bullet
void Isaac::InitBullet() {

    this->BulletTexture.loadFromFile("./Texture/Tear.png");

    this->Tear = 30;
    this->ShootSpeed = 5;
    this->ShootRange = 400;
    this->ShootDamage = 0.5;

}

//Init Isaac
void Isaac::InitIsaac() {

    //Consumables
    this->Bombs = 1;
    this->Keys = 1;

    //Stats
    this->setLife(4);
    this->setSpeed(4);
    this->InitBullet();
}

//Init Isaac Figure
void Isaac::InitIsaacFigure(Vector2f position) {

    this->xPosIsaac=position.x;
    this->yPosIsaac=position.y;

    this->IsaacTexture.loadFromFile("./Texture/Isaac.png");
    this->IsaacFigure.setTexture(&this->IsaacTexture);
    this->IsaacFigure.setPosition(this->xPosIsaac,this->yPosIsaac);
    this->IsaacFigure.setSize(Vector2f(70,80));

}

void Isaac::Draw(RenderWindow &window) {

    window.draw(this->IsaacFigure);

}


//Movement

void Isaac::Move(float dirX, float dirY) {
        this->IsaacFigure.move(this->getSpeed() * dirX, this->getSpeed() * dirY);
}

//Shoot
void Isaac::Shoot(float dirX, float dirY) {
    Vector2f pos=this->IsaacFigure.getPosition();
    this->xPosIsaac = pos.x;
    this->yPosIsaac = pos.y;
    this->bullets.push_back( new Bullet(&this->BulletTexture,this->xPosIsaac+20,this->yPosIsaac+10,dirX,dirY,this->ShootSpeed, this->ShootRange));
}

void Isaac::dropBomb() {

    this->bombs.push_back(new Bomb(Vector2f (this->IsaacFigure.getPosition().x+10,this->IsaacFigure.getPosition().y+40)));

}

Vector2f Isaac::GetPosition() {
    return Vector2f (xPosIsaac,yPosIsaac);
}







