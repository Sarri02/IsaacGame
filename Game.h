#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Floor.h"
#include "Isaac.h"

#define MaxFloor 6

using namespace sf;

class Game {
private:

    //Variables
    Event event;

    //Function private
    //Init
    void InitWindow();
    void InitVariable();
    void InitBackground();
    void pollEvents();

public:

    //Window
    RenderWindow* window;
    RectangleShape background;
    Texture texture;

    //Constructor and Destructor
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Function public
    void update();
    void render();

    //Map floor
    Floor floor[MaxFloor];
    int ActualFloor;

    //Isaac
    Isaac Isaac;

};
