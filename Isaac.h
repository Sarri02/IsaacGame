#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"


#define MaxLife 10;


using namespace sf;
using namespace std;


class Isaac {

private:
    //Consumables
    int Keys;
    int Bombs;

    //Isaac figure
    RectangleShape IsaacFigure;
    Texture * IsaacTexture;

    //Variables
    float xPosIsaac;
    float yPosIsaac;

    //Isaac
    Character isaac;

    //Private Functions
    void InitIsaac();
    void InitIsaacFigure();

public:
    //Constructor
    Isaac();

    //Bullet
    vector <Bullet*> IsaacBullets;
    float Tear;
    float ShootSpeed;
    float ShootRange;
    float ShootDamage;

    //Public Functions
    void Shoot(unsigned short int Direction, RenderWindow & window);
    //TODO void GetItem();
    void Move(unsigned short int Direction);
    void DrawIsaac(RenderWindow &window);
    void DrawConsumables(RenderWindow &window);



};