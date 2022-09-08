#include "Bullet.h"


Bullet::Bullet(float Tear, float ShootSpeed, float ShootRange, float ShootDamage, unsigned short Direction, float xPos, float yPos) {

    this->Tear = Tear;
    this->ShootSpeed = ShootSpeed;
    this->ShootRange = ShootRange;
    this->ShootDamage = ShootDamage;
    this->Direction = Direction;
    this->xPos = xPos;
    this-> yPos = yPos;

    this->bullet.setSize(Vector2f(10,10));
    this->bullet.setFillColor(Color::Blue);
    this->bullet.setPosition(xPos,yPos);

}

void Bullet::DrawBullet(RenderWindow &window) {

    window.draw(this->bullet);

}

void Bullet::UpdateBullet() {
    if(this->ShootRange>0){
        switch (this->Direction) {
            case 0:
                //up
                this->yPos-=ShootSpeed;
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
    else
        this->bullet.setFillColor(Color::Transparent);
}
