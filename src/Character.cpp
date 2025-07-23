#include <iostream>

#include "Character.h"

Character::Character(std::string name_, int hp_, int damage_, int x_, int y_,
                     std::unique_ptr<AttackStrategy> attackStrategy_) 
    : name(name_), hp(hp_), damage(damage_), x(x_), y(y_) {
    attackStrategy = std::move(attackStrategy_);
}

void Character::displayStatus() const {
    std::cout << "Name: " << name
              << ", HP: " << hp
              << ", Location: (" << x << ", " << y << ")\n";
}

void Character::attack(Character& character) {
    attackStrategy->attack(*this, character);
}  

int Character::getDamage() {
    return damage;
}

bool Character::isDead() {
    return hp <= 0;
}

void Character::applyDamage(int damage) {
    hp -= damage;
}