#include "Bullet.h"


Bullet::Bullet() {

    this->InitBullet(0,0,0,0);
    this->xPosBullet = 0;
    this->yPosBullet = 0;

    this->BulletFigure.setSize(Vector2f(20,20));
    this->BulletFigure.setFillColor(Color::Blue);
    this->BulletFigure.setPosition(0,0);


}

void Bullet::DrawBullet(RenderWindow &window) {

    window.draw(this->BulletFigure);

}

void Bullet::InitBullet(float tears, float speed, float damage, float range) {

    this->Tears = tears;
    this->ShootSpeed = speed;
    this->ShootDamage = damage;
    this->ShootRange = range;

}
