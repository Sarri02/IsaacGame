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
    int KeyTime;
    //Game Background
    RectangleShape background;
    Texture texture;

    //Map floor
    Floor floor[MaxFloor];
    int ActualFloor;

    //Isaac
    Isaac Isaac;

    //Texture Stats
    Texture texture1;

    //Function private
    //Init
    void InitWindow();
    void InitVariable();
    void InitBackground();
    void InitTexture();

public:

    //Window
    RenderWindow* window;

    //Constructor and Destructor
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Function public
    //Update
    void updatePollEvents();
    void updateInput();
    void updateIsaac();
    void updateBullet();
    void update();
    //Render
    void renderBackground();
    void renderMap();
    void renderStats();
    void renderIsaac();
    void renderBullet();
    void render();
};
