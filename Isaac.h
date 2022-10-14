#ifndef ISAAC_ISAAC_H
#define ISAAC_ISAAC_H

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"

#define MaxLife 10;

using namespace sf;
using namespace std;


class Isaac: public Character{
private:

    //Variables
    float xPosIsaac;
    float yPosIsaac;


    //Private Functions
    void InitIsaac();
    void InitIsaacFigure(Vector2f position);
    void InitBullet();

public:
    //Isaac
    Character isaac;

    //Isaac figure
    RectangleShape IsaacFigure;
    Texture IsaacTexture;
    Texture BulletTexture;

    //Bullet
    float Tear;
    float ShootSpeed;
    float ShootRange;

    //TODO float ShootDamage;
    vector <Bullet*> bullets;


    //Consumables
    int Keys;
    int Bombs;

    //Constructor
    Isaac(Vector2f position);
    virtual ~Isaac();

    //Public Functions
    void Shoot(float dirX, float dirY);
    void Move(float dirX, float dirY);
    //TODO void GetItem();
    void DrawIsaac(RenderWindow &window);

};

#endif