#include <SFML/Graphics.hpp>

using namespace sf;

class Door {
private:
    //Variables
    int TypeDoor;
    bool IsOpen;
    RectangleShape door;
    Texture doorTexture;

    //Private function
    void InitDoor();

public:
    //Constructor and Destructor
    Door();

    //Public function
    void ChangeRoom();
};