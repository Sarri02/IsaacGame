#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"

#define MaxLife 10;

using namespace sf;
using namespace std;


class Isaac: public Sprite{
private:

    //Variables
    float xPosIsaac;
    float yPosIsaac;


    //Private Functions
    void InitIsaac();
    void InitBullet();
    bool MoveIsPossible(float dirX, float dirY);

public:
    //Isaac
    Character isaac;

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
    Isaac();
    virtual ~Isaac();

    //Public Functions
    void Shoot(float dirX, float dirY);
    void Move(float dirX, float dirY);
    //TODO void GetItem();


};