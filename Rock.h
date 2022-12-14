#ifndef ISAAC_ROCK_H
#define ISAAC_ROCK_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Rock{
private:

    Texture texture;

public:
    Rock(Vector2f position);
    virtual ~Rock();

    RectangleShape rock;

    void DrawRock(RenderWindow & window);

    bool isSigned;
};

#endif