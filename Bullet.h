#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Bullet {

private:

    //Variables
    float Tears;
    float ShootSpeed;
    float ShootDamage;
    float ShootRange;

    //BulletFigure

    RectangleShape BulletFigure;
    //TODO Texture


public:
    //Constructor
    Bullet();


    //Public Functions
    //TODO void Collision();
    void InitBullet(float tears, float speed, float damage, float range);
    void DrawBullet(RenderWindow &window);

    //BulletPosition
    float xPosBullet;
    float yPosBullet;

};