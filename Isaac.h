#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"


#define MaxLife 10;


using namespace sf;

class Isaac {

private:
    //Isaac figure
    RectangleShape IsaacFigure;
    Texture * IsaacTexture;

    //Variables
    int xPosIsaac;
    int yPosIsaac;
    //Consumables
    int Keys;
    int Bombs;
    //Isaac
    Character isaac;
    Bullet *IsaacTear;

    //Private Functions
    void InitIsaac();
    void InitIsaacFigure();

public:
    //Constructor
    Isaac();

    //Public Functions
    void Shoot(unsigned short int Direction);
    //TODO void GetItem();
    void Move(unsigned short int Direction);
    void DrawIsaac(RenderWindow &window);
    void DrawConsumables(RenderWindow &window);


};