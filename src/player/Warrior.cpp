#include <iostream>

#include "player/Warrior.h"

Warrior::Warrior(const std::string& name)
    : Player(name, 150, 0) {}

void Warrior::attack() {
    std::cout << name << " swings a mighty sword.\n";
}