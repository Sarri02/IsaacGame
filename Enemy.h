#ifndef ISAAC_CPP_ENEMY_H
#define ISAAC_CPP_ENEMY_H


#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Isaac.h"
#include "Bullet.h"

class Enemy: public Character {
private:


public:
    virtual ~Enemy();

    //Enemy figure
    RectangleShape EnemyFigure;
    Texture EnemyTexture;
    void Draw(RenderWindow &window) override;
    bool CheckCollision(RectangleShape one, RectangleShape two);
    virtual void InitFigure(Vector2f position) = 0;
    virtual void InitEnemy()=0;
    virtual void UpdateEnemy(Isaac isaac)=0;
    virtual void Move(float dirX, float dirY)=0;

};


#endif
