#include <SFML/Graphics.hpp>

using namespace sf;

class Rock{
private:
    bool isSigned;
public:
    Rock(Vector2f position);
    virtual ~Rock();

    RectangleShape rock;
    Texture texture;

    void DrawRock(RenderWindow & window);

    //TODO drop item if is signed

};
