#include "Isaac.h"
#include <iostream>



//Constructor
Isaac::Isaac() {

    this->InitIsaac();

}

Isaac::~Isaac() = default;

//Bullet
void Isaac::InitBullet() {

    this->BulletTexture.loadFromFile("./Texture/Tear.png");

    this->Tear = 40;
    this->ShootSpeed = 4.5;
    this->ShootRange = 400;
    //TODO this->ShootDamage = 1;

}

//Init Isaac
void Isaac::InitIsaac() {

    //Consumables
    this->Bombs = 1;
    this->Keys = 1;

    //Stats
    this->isaac.setLife(4);
    this->isaac.setSpeed(3.2);
    this->InitBullet();
}

//Movement
bool Isaac::MoveIsPossible(float dirX, float dirY) {
    Vector2f pos = getPosition();
    float x = pos.x;
    float y = pos.y;
    x+=(dirX*this->isaac.getSpeed());
    y+=(dirY*this->isaac.getSpeed());
    return (x<880 && x>40 && y<615 && y>215);
}
void Isaac::Move(float dirX, float dirY) {
    if(this->MoveIsPossible(dirX,dirY))
        move(this->isaac.getSpeed() * dirX, this->isaac.getSpeed() * dirY);
}

//Shoot
void Isaac::Shoot(float dirX, float dirY) {
    Vector2f pos = getPosition();
    this->xPosIsaac = pos.x;
    this->yPosIsaac = pos.y;
    this->bullets.push_back( new Bullet(&this->BulletTexture,this->xPosIsaac+20,this->yPosIsaac+10,dirX,dirY,this->ShootSpeed, this->ShootRange));
}







