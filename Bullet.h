#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;


class Bullet{
private:
    //Figure
    RectangleShape bulletFigure;

    //Variables
    Vector2<float> direction;
    float speed;

public:

    //Constructor and Destructor
    Bullet();
    Bullet(Texture *texture, float xPos, float yPos, float xDir, float yDir, float speed);
    virtual ~Bullet();

    //Public Functions
    void updateBullet();
    void drawBullet (RenderWindow & window);

};