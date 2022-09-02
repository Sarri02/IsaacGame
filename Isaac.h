#include <SFML/Graphics.hpp>
#include "Character.h"


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

    //Private Functions
    void InitIsaac();
    void InitIsaacFigure();

public:
    //Constructor
    Isaac();

    //Public Functions
    //TODO void Shoot
    //TODO void GetItem();
    void Move(unsigned short int Direction);
    void DrawIsaac(RenderWindow &window);
    void DrawConsumables(RenderWindow &window);



};