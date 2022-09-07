#include "Bullet.h"


Bullet::Bullet(float Tear, float ShootSpeed, float ShootRange, float ShootDamage, unsigned short Direction, float xPos, float yPos) {

    this->bullet.setSize(Vector2f(10,10));
    this->bullet.setFillColor(Color::Blue);
    this->bullet.setPosition(xPos,yPos);
    while(ShootRange>0){
        switch (Direction) {
            case 0:
                //up
                yPos-=ShootSpeed;
                break;
            case 1:
                //right
                xPos+=ShootSpeed;
                break;
            case 2:
                //down
                yPos+=ShootSpeed;
                break;
            case 3:
                //left
                xPos-=ShootSpeed;
                break;
            default:
                break;
        }
        this->bullet.setPosition(xPos,yPos);
        ShootRange-=ShootSpeed;
    }
}

void Bullet::DrawBullet(RenderWindow &window) {

    window.draw(this->bullet);

}
