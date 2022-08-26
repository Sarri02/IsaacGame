#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"


#define MaxLife 10;


using namespace sf;

class Isaac {

private:
    //Isaac figure
    RectangleShape IsaacFigure;
    //TODO Texture IsaacTexture;



    //Variables
    //Consumables
    int Keys;
    int Bombs;

    Character isaac;
    //Private Functions
    void InitIsaac();
    void InitIsaacFigure();

public:
    //Constructor
    Isaac();

    Bullet *IsaacTear;


    int xPosIsaac;
    int yPosIsaac;

    //Public Functions
    //TODO void Shoot();
    //TODO void GetItem();
    void Move(unsigned short int Direction);
    void DrawIsaac(RenderWindow &window);


};