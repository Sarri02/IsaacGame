#include <SFML/Graphics.hpp>
#include "Room.h"


#define MaxRooms 12
#define FloorDimension 7

using namespace sf;

class Floor {

private:
    //Private Functions
    void GenerateFloor();
    void RandomValidRoomCoordinate(int &x, int &y);
public:
    //Constructor and Destructor
    Floor();

    //Map
    Room room[FloorDimension][FloorDimension];
    void DrawMap(RenderWindow &window);
};