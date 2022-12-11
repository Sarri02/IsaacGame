#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() {
    InitItem();
}

void Item::InitItem() {
    Animation=0;
    Type=rand()%6;
    ItemFigure.setSize(Vector2f(100,100));
    ItemFigure.setPosition(Vector2f(444,400));
}

void Item::UpGradeIsaac(Isaac & isaac) {
    switch (Type) {
        case 0:
            isaac.setLife(isaac.getLife()+2);//+2 life
            cout<<"vita";
            break;
        case 1:
            isaac.Tear-=15;//velocità di ricarica colpi
            cout<<"vel. ricarica";
            break;
        case 2:
            isaac.ShootSpeed+=5;//velocità colpi
            cout<<"vel. colpi";
            break;
        case 3:
            isaac.ShootRange+=250;//distanza massima colpi
            cout<<"gittata";
            break;
        case 4:
            isaac.ShootDamage+=1;//aumenta danno
            cout<<"danno";
            break;
        case 5:
            isaac.setSpeed(isaac.getSpeed()+3);//aumenta velocita
            cout<<"vel.";
            break;
        default:
            break;
    }


}

bool Item::UpdateItem(Isaac & isaac, bool Collision) {
    //Animation
    switch (Type) {
        case 0:
            ItemTexture.loadFromFile("./Texture/Up1.png");
            ItemFigure.setTexture(&ItemTexture);
            break;
        case 1:
            ItemTexture.loadFromFile("./Texture/Up2.png");
            ItemFigure.setTexture(&ItemTexture);
            break;
        case 2:
            ItemTexture.loadFromFile("./Texture/Up3.png");
            ItemFigure.setTexture(&ItemTexture);
            break;
        case 3:
            ItemTexture.loadFromFile("./Texture/Up4.png");
            ItemFigure.setTexture(&ItemTexture);
            break;
        case 4:
            ItemTexture.loadFromFile("./Texture/Up5.png");
            ItemFigure.setTexture(&ItemTexture);
            break;
        case 5:
            ItemTexture.loadFromFile("./Texture/Up6.png");
            ItemFigure.setTexture(&ItemTexture);
            break;
        default:
            break;
    }
    while(!Collision){
        if(Animation%20<10)
            ItemFigure.move(0,-2);
        else
            ItemFigure.move(0,2);
        Animation++;
        return true;
    }
    UpGradeIsaac(isaac);
    return false;
}

void Item::DrawItem(RenderWindow &window) {

    window.draw(ItemFigure);

}


Item::~Item() = default;

