#include <SFML/Graphics.hpp>
#include "Character.h"


#define MaxLife 10;


using namespace sf;
using namespace std;


class Isaac {
private:
    //Isaac figure
    Sprite IsaacFigure;
    Texture IsaacTexture;

    //Bullet
    float Tear;
    float ShootSpeed;
    float ShootRange;
    float ShootDamage;
    //Variables
    float xPosIsaac;
    float yPosIsaac;


    //Private Functions
    void InitIsaac();
    void InitIsaacFigure();
    bool MoveIsPossible(float dirX, float dirY);

public:
    //Isaac
    Character isaac;

    //Consumables
    int Keys;
    int Bombs;

    //Constructor
    Isaac();

    //Public Functions
    void Shoot(unsigned short int Direction);
    //TODO void GetItem();
    void Move(float dirX, float dirY);
    void DrawIsaac(RenderWindow &window);

};