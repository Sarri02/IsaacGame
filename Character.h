#include <SFML/Graphics.hpp>


using namespace sf;

class Character{

private:

    //Variables
    float Life;
    float Speed;

    //Private Functions

public:

    //TODO bool CanFly;
    //TODO int MoveSet;

    //Public Functions
    void setLife(float Life);
    void setSpeed(float Speed);
    float getLife();
    float getSpeed();
    //TODO void TakeDamage();

};