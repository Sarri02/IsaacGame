

#include "Enemy.h"

void Enemy::Draw(RenderWindow &window) {

    window.draw(this->EnemyFigure);

}

Enemy::~Enemy() = default;

bool Enemy::CheckCollision(RectangleShape one, RectangleShape two) {

    bool collisionX = one.getPosition().x + one.getSize().x >= two.getPosition().x &&
                      two.getPosition().x + two.getSize().x >= one.getPosition().x;
    bool collisionY = one.getPosition().y + one.getSize().y >= two.getPosition().y &&
                      two.getPosition().y + two.getSize().y >= one.getPosition().y;
    return collisionX && collisionY;

}

