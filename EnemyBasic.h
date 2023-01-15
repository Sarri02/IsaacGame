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
    ~EnemyBasic();

    void InitFigure(Vector2f position) override;
    void InitEnemy() override;
    void UpdateEnemy(Isaac isaac) override;
    void Move(float dirX, float dirY) override;
};


#endif
