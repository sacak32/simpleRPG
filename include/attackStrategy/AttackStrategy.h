#pragma once

class Character; // Forward declaration

class AttackStrategy {
public:
    AttackStrategy() = default;
    
    virtual void attack(Character& source, Character& target) = 0;
};