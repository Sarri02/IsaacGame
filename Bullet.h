#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet {


private:

    RectangleShape bullet;
    //TODO Texture;


    //Private Functions

public:
    //Constructor and Destructor
    Bullet();
    Bullet(float Tear, float ShootSpeed, float ShootRange, float ShootDamage, unsigned short int Direction, float xPos, float yPos);

    //Public Functions
    void DrawBullet(RenderWindow & window);

};
