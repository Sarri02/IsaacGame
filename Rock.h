#include <SFML/Graphics.hpp>

using namespace sf;

class Rock: public sf::RectangleShape{
public:
    Texture texture;
    bool isSigned;
private:
    Rock(Vector2f position);
    virtual ~Rock();

    //TODO drop item if is signed

};
