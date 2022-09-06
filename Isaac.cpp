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
    this->isaac.Speed = 6;

    //TODO this->IsaacTear->InitBullet(10,30, 1, 100);


}

//Init Isaac Figure
void Isaac::InitIsaacFigure() {

    this->xPosIsaac=445;
    this->yPosIsaac=380;

    this->IsaacFigure.setSize(Vector2f(60,70));
    this->IsaacTexture->loadFromFile("../Texture/Isaac.png");
    this->IsaacFigure.setTexture(this->IsaacTexture);
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

void Isaac::DrawConsumables(RenderWindow &window) {

    //Bombs
    int xPosBombs = 420, yPosBombs = 43;
    for(int k=0; k< this->Bombs; k++)
    {
        RectangleShape bomb;
        bomb.setSize(Vector2f(32,32));
        bomb.setFillColor(Color::Black);
        bomb.setPosition(xPosBombs,yPosBombs);
        //TODO add texture

        window.draw(bomb);
        xPosBombs += 46;
    }

    //Keys
    int xPosKeys = 420, yPosKeys = 123;
    for(int k=0; k< this->Keys; k++)
    {
        RectangleShape key;
        key.setSize(Vector2f(32,32));
        key.setFillColor(Color::Yellow);
        key.setPosition(xPosKeys,yPosKeys);
        //TODO add texture

        window.draw(key);
        xPosKeys += 46;
    }

    //Life
    int xPosLife = 64, yPosLife = 60;
    for(int k=0; k < this->isaac.Life; k++)
    {
        RectangleShape key;
        key.setSize(Vector2f(42,42));
        key.setFillColor(Color::Red);
        key.setPosition(xPosLife,yPosLife);
        //TODO add texture

        window.draw(key);
        if(k==4){
            xPosLife=64;
            yPosLife+=52;

        }
        else
            xPosLife += 60;
    }

}



