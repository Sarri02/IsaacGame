#include <SFML/Graphics.hpp>
#include "Door.h"

using namespace sf;

class Room {
private:

    //Private function
    void InitRoom();

public:

    //Variables
    //TODO bool Visited;
    int TypeRoom;

    //Constructor and Destructor
    Room();

    //Public function
    //TODO deve posizionare i vari oggetti nella room
    void GenerateRoom();
};