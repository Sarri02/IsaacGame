#pragma once

#ifndef ISAAC_GAME_H
#define ISAAC_GAME_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Floor.h"
#include "Character.h"
#include "AchievementsDisplay.h"


#define MaxFloor 6

using namespace sf;

class Game {
private:
    //Variables
    int KeyTime;
    //Game Background
    RectangleShape background;
    Texture texture;

    //Texture Stats
    Texture textureStats;

    //Texture Missions
    Texture textureM[3];

    //Function private
    static bool CheckCollision(RectangleShape one, RectangleShape two);

    //Init
    void InitWindow();
    void InitVariable();
    void InitBackground();
    void InitTexture();

    //Update
    void updatePollEvents();
    void updateInput();
    void updateIsaac();
    void updateBullet();
    void updateBomb();
    void updateRoom();
    void updateEnemies();

    //Render
    void renderBackground();
    void renderMap();
    void renderStats();
    void renderIsaac();
    void renderBullet();
    void renderBomb();
    void renderActualRoom();

public:

    //Window
    unique_ptr<RenderWindow> window;

    //Constructor and Destructor
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Isaac
    unique_ptr<Isaac> isaac;
    bool IsaacMoveIsPossible(float dirX, float dirY);
    unique_ptr<AchievementsDisplay>  missions[3];


    //Map floor
    Floor floor[MaxFloor];
    int ActualFloor;

    //Function public

    void update();

    void render();
};

#endif