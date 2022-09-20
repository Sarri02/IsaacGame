#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"


#define MaxLife 10;


using namespace sf;
using namespace std;


class Isaac {
private:
    //Isaac figure
    Sprite IsaacFigure;
    Texture IsaacTexture;
    Texture BulletTexture;

    //Variables
    float xPosIsaac;
    float yPosIsaac;


    //Private Functions
    void InitIsaac();
    void InitIsaacFigure();
    void InitBullet();
    bool MoveIsPossible(float dirX, float dirY);

public:
    //Isaac
    Character isaac;
    //Bullet
    float Tear;
    float ShootSpeed;
    float ShootRange;
    float ShootDamage;
    vector <Bullet*> bullets;


    //Consumables
    int Keys;
    int Bombs;

    //Constructor
    Isaac();

    //Public Functions
    void Shoot(float dirX, float dirY);
    //TODO void GetItem();
    void Move(float dirX, float dirY);
    void DrawIsaac(RenderWindow &window);

};