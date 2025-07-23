#pragma once

#include <string>

#include "Character.h"

class Player : public Character {
public:
    // Constructor
    Player(const std::string& name, int hp, int damage);

    // Move by dx and dy
    void move(int dx, int dy);
};