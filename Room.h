#ifndef ISAAC_ROOM_H
#define ISAAC_ROOM_H

#include <SFML/Graphics.hpp>
#include "Door.h"
#include "Rock.h"
#include "Enemy.h"
#include "Item.h"


using namespace sf;
using namespace std;



class Room {
private:

    //Private function
    void InitRoom();

public:

    //Variables
    int TypeRoom;

    //Doors
    unique_ptr<Door> DoorUp, DoorRight, DoorDown, DoorLeft;

    //Obstacles
    vector <Rock*> Roocks;
    vector <Enemy*> Enemies;
    vector <Item*> Items;



    //Constructor
    Room();
    virtual ~Room();


    //Public function

};

#endif