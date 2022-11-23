#ifndef ISAAC_CPP_ENEMYBASIC_H
#define ISAAC_CPP_ENEMYBASIC_H

#include "Enemy.h"


class EnemyBasic: public Enemy {
private:
    int textureNumber;
    int DirX;
    int DirY;

public:
    EnemyBasic(Vector2f position);
    virtual ~EnemyBasic();

    void InitFigure(Vector2f position);
    void InitEnemy();
    void UpdateEnemy(Isaac isaac);
    void Move(float dirX, float dirY);
};


#endif
