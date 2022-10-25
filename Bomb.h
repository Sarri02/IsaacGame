#ifndef ISAAC_BOMB_H
#define ISAAC_BOMB_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Bomb {
private:
    Texture texture;

    int time;

public:
    Bomb(Vector2f position);
    virtual ~Bomb();

    RectangleShape bomb;
    RectangleShape explosion;

    bool updateBomb();
    void DrawBomb(RenderWindow & window);


};


#endif
