#include "Character.h"

void Character::setLife(float Life) {
    this->Life=Life;
}

void Character::setSpeed(float Speed) {
    this->Speed=Speed;
}

float Character::getLife() {
    return this->Life;
}

float Character::getSpeed() {
    return this->Speed;
}

void Character::TakeDamage(float damage) {

    this->Life-=damage;

}

Character::~Character() = default;

