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
    //TODO rendere privato

    //Constructor
    Room();

    //Public function
    //TODO deve posizionare i vari oggetti nella room
    void GenerateRoom();
};