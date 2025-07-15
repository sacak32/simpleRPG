#include <iostream>

#include "player/Archer.h"

Archer::Archer(const std::string& name)
    : Player(name, 100, 50) {}

void Archer::attack() {
    std::cout << name << " shoots an arrow.\n";
}