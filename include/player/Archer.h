#pragma once

#include "player/Player.h"

class Archer : public Player {
public:
    // Constructor
    Archer(const std::string& name);

    // Performs the attack
    void attack() override;
};