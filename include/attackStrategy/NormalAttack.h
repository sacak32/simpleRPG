#pragma once

#include "attackStrategy/AttackStrategy.h"

class NormalAttack : public AttackStrategy {
public:
    NormalAttack() = default;

    void attack(Character& source, Character& target) override;
};