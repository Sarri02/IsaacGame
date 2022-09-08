#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet {


private:

    float Tear;
    float ShootSpeed;
    float ShootRange;
    float ShootDamage;
    unsigned short Direction;
    float xPos;
    float yPos;

    RectangleShape bullet;
    //TODO Texture;


    //Private Functions

public:
    //Constructor and Destructor
    Bullet(float Tear, float ShootSpeed, float ShootRange, float ShootDamage, unsigned short int Direction, float xPos, float yPos);

    //Public Functions
    void UpdateBullet();
    void DrawBullet(RenderWindow & window);

};
