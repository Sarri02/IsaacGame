
#include "EnemyBasic.h"

void EnemyBasic::InitFigure(Vector2f position) {
    this->EnemyTexture.loadFromFile("./Texture/Fly1.png");
    this->EnemyFigure.setTexture(&this->EnemyTexture);
    this->EnemyFigure.setPosition(position);
    this->EnemyFigure.setSize(Vector2f(40,40));
}

void EnemyBasic::InitEnemy() {
    this->textureNumber=0;

    this->setSpeed(0.8);
    this->setLife(1.5);
    //TODO damage();
}

void EnemyBasic::UpdateEnemy(Isaac isaac) {
    //Texture Animation
    if(this->textureNumber%6<3){
        this->EnemyTexture.loadFromFile("./Texture/Fly2.png");
        this->EnemyFigure.setTexture(&this->EnemyTexture);
        this->textureNumber++;
    }
    else{
        this->EnemyTexture.loadFromFile("./Texture/Fly1.png");
        this->EnemyFigure.setTexture(&this->EnemyTexture);
        this->textureNumber++;
    }

    //IAMove
    if(isaac.IsaacFigure.getPosition().x+12>this->EnemyFigure.getPosition().x)
        this->DirX=1;
    else
    if(isaac.IsaacFigure.getPosition().x+12<this->EnemyFigure.getPosition().x)
        this->DirX=-1;
    else
        this->DirX=0;
    if(isaac.IsaacFigure.getPosition().y-2>this->EnemyFigure.getPosition().y)
        this->DirY=1;
    else
    if(isaac.IsaacFigure.getPosition().y-2<this->EnemyFigure.getPosition().y)
        this->DirY=-1;
    else
        this->DirY=0;

    for (int i = isaac.bullets.size() - 1; i >= 0; i--)
    {
        if(this->CheckCollision(this->EnemyFigure,isaac.bullets[i]->bulletFigure) )
        {
            isaac.bullets[i]->bulletFigure.setPosition(Vector2f(2000,2000));
            this->TakeDamage(isaac.ShootDamage);
            this->Move(30 * isaac.bullets[i]->direction.x,30 * isaac.bullets[i]->direction.y);
        }

    }

    this->Move(this->getSpeed() * this->DirX, this->getSpeed() * this->DirY);
}


EnemyBasic::EnemyBasic(Vector2f position) {
    this->InitEnemy();
    this->InitFigure(position);
}


void EnemyBasic::Move(float dirX, float dirY) {
    this->EnemyFigure.move(this->getSpeed()*dirX,this->getSpeed()*dirY);
}

EnemyBasic::~EnemyBasic() {

}

