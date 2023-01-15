#ifndef ISAAC_ISAAC_H
#define ISAAC_ISAAC_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Character.h"
#include "Bullet.h"
#include "Bomb.h"
#include "Observer.h"


using namespace sf;
using namespace std;

class Isaac:  public Character{
private:


    //Variables
    float xPosIsaac;
    float yPosIsaac;

    //Private Functions
    void InitIsaac();
    void InitIsaacFigure(Vector2f position);
    void InitBullet();

public:

    //Isaac figure
    RectangleShape IsaacFigure;
    Texture IsaacTexture;
    Texture BulletTexture;

    //Bullet
    float Tear;
    float ShootSpeed;
    float ShootRange;
    float ShootDamage;
    vector <Bullet*> bullets;
    vector <Bomb*> bombs;


    //Consumables
    int Keys;
    int Bombs;

    //Constructor
    Isaac(Vector2f position);
    virtual ~Isaac();

    //Public Functions
    Vector2f GetPosition();
    void Shoot(float dirX, float dirY);
    void dropBomb();
    void Move(float dirX, float dirY);
    void Draw(RenderWindow &window);

    //Achievement
    list< Observer* > observers;
    int shoot;
    int kill;
    int room;

    virtual void registerObserver(Observer* obs) {
        observers.push_back(obs);    }
    virtual void removeObserver(Observer* obs) {
        observers.remove(obs);    }


};

#endif