#include <SFML/Graphics.hpp>

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


    //Constructor
    Room();
    virtual ~Room();


    //Public function
    //TODO deve posizionare i vari oggetti nella room
    void GenerateRoom();

};