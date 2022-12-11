#ifndef FLOOR_CPP_ITEM_H
#define FLOOR_CPP_ITEM_H

#include <SFML/Graphics.hpp>
#include "Isaac.h"

using namespace sf;

class Item{
private:

    int Type;
    int Animation;

    void UpGradeIsaac(Isaac & isaac);
    void InitItem();


public:

    Item();
    virtual ~Item();

    RectangleShape ItemFigure;
    Texture ItemTexture;

    bool UpdateItem(Isaac & isaac, bool Collision);
    void DrawItem(RenderWindow & window);

};


#endif
