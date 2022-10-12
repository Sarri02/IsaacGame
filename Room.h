#include <SFML/Graphics.hpp>
#include "Door.h"
#include "Rock.h"

using namespace sf;
using namespace std;



class Room {
private:

    //Private function
    void InitRoom();

public:

    //Variables
    //TODO bool Visited;
    int TypeRoom;

    //Doors
    unique_ptr<Door> DoorUp, DoorRight, DoorDown, DoorLeft;

    //Obstacles
    vector <Rock*> Roocks;

    //Constructor
    Room();
    virtual ~Room();


    //Public function

};