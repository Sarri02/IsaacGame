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

    //Map
    Room room[FloorDimension][FloorDimension];
    Vector2i ActualRoom;

    //Constructor and Destructor
    Floor();
    virtual ~Floor();

    void GenerateDoors(int x, int y);
    void GenerateRoom(int x, int y);
    void DrawActualRoom(RenderWindow &window);
    void DrawMap(RenderWindow &window);
};