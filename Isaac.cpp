#include "Isaac.h"

//Constructor
Isaac::Isaac() {

    InitIsaac();
    InitIsaacFigure();

}

//Init Isaac
void Isaac::InitIsaac() {
    //Consumables
    this->Bombs = 1;
    this->Keys = 1;
    //Stats
    this->isaac.Life = 4;
    this->isaac.CanFly = false;
    this->isaac.Speed = 8;

    //TODO this->IsaacTear->InitBullet(10,30, 1, 100);



}

//Init Isaac Figure
void Isaac::InitIsaacFigure() {

    this->xPosIsaac=445;
    this->yPosIsaac=380;

    this->IsaacFigure.setSize(Vector2f(60,70));
    //TODO this->IsaacTexture.loadFromFile("../Texture/Isaac.png");
    //TODO this->IsaacFigure.setTexture(&(this->IsaacTexture));
    this->IsaacFigure.setPosition(this->xPosIsaac,this->yPosIsaac);

}


void Isaac::DrawIsaac(RenderWindow &window) {

    window.draw(this->IsaacFigure);

}

void Isaac::Move(unsigned short int Direction) {
    switch (Direction) {
        case 0:
            //up
            yPosIsaac -=this->isaac.Speed;
            break;
        case 1:
            //right
            xPosIsaac +=this->isaac.Speed;
            break;
        case 2:
            //down
            yPosIsaac +=this->isaac.Speed;
            break;
        case 3:
            //left
            xPosIsaac -=this->isaac.Speed;
            break;
        default:
            break;
    }
    this->IsaacFigure.setPosition(this->xPosIsaac,this->yPosIsaac);

}
