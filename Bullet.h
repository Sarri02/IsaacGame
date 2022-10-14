#ifndef ISAAC_BULLET_H
#define ISAAC_BULLET_H

#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;


class Bullet{
private:
    //Figure
    Sprite bulletFigure;

    //Variables
    Vector2<float> direction;
    float speed;
    float range;

    bool MoveIsPossible(float dirX, float dirY);

public:

    //Constructor and Destructor
    Bullet(Texture *texture, float xPos, float yPos, float xDir, float yDir, float speed, float range);
    virtual ~Bullet();

    //Public Functions
    bool updateBullet();
    void drawBullet (RenderWindow & window);

};

#endif