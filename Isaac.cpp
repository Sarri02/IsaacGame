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
    this->isaac.Life = 4;
    this->isaac.CanFly = false;
    this->isaac.Speed = 3;
    this->InitBullet();
}

//Init Isaac Figure
void Isaac::InitIsaacFigure(Vector2f position) {

    this->xPosIsaac=position.x;
    this->yPosIsaac=position.y;

    this->IsaacTexture.loadFromFile("./Texture/Isaac.png");
    this->IsaacFigure.setTexture(this->IsaacTexture);
    this->IsaacFigure.setPosition(this->xPosIsaac,this->yPosIsaac);

}

void Isaac::DrawIsaac(RenderWindow &window) {

    window.draw(this->IsaacFigure);

}

//Movement
bool Isaac::MoveIsPossible(float dirX, float dirY) {
    Vector2f pos=this->IsaacFigure.getPosition();
    float x = pos.x;
    float y = pos.y;
    x+=(dirX*this->isaac.Speed);
    y+=(dirY*this->isaac.Speed);
    return (x<880 && x>40 && y<615 && y>215);
}
void Isaac::Move(float dirX, float dirY) {
    if(this->MoveIsPossible(dirX,dirY))
        this->IsaacFigure.move(this->isaac.Speed * dirX, this->isaac.Speed * dirY);
}


void Isaac::Shoot(float dirX, float dirY) {
    Vector2f pos=this->IsaacFigure.getPosition();
    this->xPosIsaac = pos.x;
    this->yPosIsaac = pos.y;
    this->bullets.push_back( new Bullet(&this->BulletTexture,this->xPosIsaac+20,this->yPosIsaac+10,dirX,dirY,this->ShootSpeed, this->ShootRange));
}







