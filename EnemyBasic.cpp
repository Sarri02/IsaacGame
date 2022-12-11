
#include "EnemyBasic.h"

void EnemyBasic::InitFigure(Vector2f position) {
    EnemyTexture.loadFromFile("./Texture/Fly1.png");
    EnemyFigure.setTexture(&EnemyTexture);
    EnemyFigure.setPosition(position);
    EnemyFigure.setSize(Vector2f(40,40));
}

void EnemyBasic::InitEnemy() {
    textureNumber=0;

    setSpeed(0.8);
    setLife(1.5);
}

void EnemyBasic::UpdateEnemy(Isaac isaac) {
    //Texture Animation
    if(textureNumber%6<3){
        EnemyTexture.loadFromFile("./Texture/Fly2.png");
        EnemyFigure.setTexture(&EnemyTexture);
        textureNumber++;
    }
    else{
        EnemyTexture.loadFromFile("./Texture/Fly1.png");
        EnemyFigure.setTexture(&EnemyTexture);
        textureNumber++;
    }

    //IAMove
    if(isaac.IsaacFigure.getPosition().x+12>EnemyFigure.getPosition().x)
        DirX=1;
    else
    if(isaac.IsaacFigure.getPosition().x+12<EnemyFigure.getPosition().x)
        DirX=-1;
    else
        DirX=0;
    if(isaac.IsaacFigure.getPosition().y-2>EnemyFigure.getPosition().y)
        DirY=1;
    else
    if(isaac.IsaacFigure.getPosition().y-2<EnemyFigure.getPosition().y)
        DirY=-1;
    else
        DirY=0;

    for (int i = isaac.bullets.size() - 1; i >= 0; i--)
    {
        if(CheckCollision(EnemyFigure,isaac.bullets[i]->bulletFigure) )
        {
            isaac.bullets[i]->bulletFigure.setPosition(Vector2f(2000,2000));
            TakeDamage(isaac.ShootDamage);
            Move(30 * isaac.bullets[i]->direction.x,30 * isaac.bullets[i]->direction.y);
        }

    }

    Move(getSpeed() * DirX, getSpeed() * DirY);
}


EnemyBasic::EnemyBasic(Vector2f position) {
    InitEnemy();
    InitFigure(position);
}


void EnemyBasic::Move(float dirX, float dirY) {
    EnemyFigure.move(getSpeed()*dirX,getSpeed()*dirY);
}

EnemyBasic::~EnemyBasic() {

}

