#pragma once

#include "attackStrategy/AttackStrategy.h"

class AggressiveAttack : public AttackStrategy {
public:
    AggressiveAttack() = default;

    void attack(Character& source, Character& target) override;
};