#include <SFML/Graphics.hpp>

using namespace sf;


class Room {
private:

    //Private function
    void InitRoom();

public:

    //Variables
    //TODO bool Visited;
    int TypeRoom;


    //Constructor
    Room();
    virtual ~Room();


    //Public function
    //TODO void GenerateRoom();

};