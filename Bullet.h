#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;


class Bullet{
private:
    //Figure
    Sprite bulletFigure;

    //Variables
    Vector2<float> direction;
    float speed;

    bool MoveIsPossible(float dirX, float dirY);

public:

    //Constructor and Destructor
    Bullet();
    Bullet(Texture *texture, float xPos, float yPos, float xDir, float yDir, float speed);
    virtual ~Bullet();

    //Public Functions
    bool updateBullet();
    void drawBullet (RenderWindow & window);

};