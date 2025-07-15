#include <iostream>

#include "player/Mage.h"

Mage::Mage(const std::string& name)
    : Player(name, 50, 100) {}

void Mage::attack() {
    std::cout << name << " casts a spell.\n";
}