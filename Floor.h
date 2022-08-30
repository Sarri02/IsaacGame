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
    //Map
    Room room[FloorDimension][FloorDimension];
public:
    //Constructor and Destructor
    Floor();

    void DrawMap(RenderWindow &window);
};