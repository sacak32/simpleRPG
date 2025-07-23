#include <iostream>

#include "player/Player.h"
#include "attackStrategy/NormalAttack.h"

Player::Player(const std::string& name_, int hp_, int damage_) 
    : Character(name_, hp_, damage_, 0, 0, std::make_unique<NormalAttack>()) {}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
    std::cout << name << " moves to (" << x << ", " << y << ")\n";
}