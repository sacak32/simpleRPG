#pragma once

#include <memory>
#include <string>

#include "attackStrategy/AttackStrategy.h"

class Character {
public:
    // Constructor
    Character(std::string name_, int hp_, int damage_, int x_, int y_, 
              std::unique_ptr<AttackStrategy> attackStrategy_);

    // Prints out the status
    void displayStatus() const;

    // Performs the attack
    void attack(Character& character);

    // Getter for damage
    int getDamage();
    
    // Is character dead?
    bool isDead();

    // Applies the given damage
    void applyDamage(int damage);

protected:
    std::string name;       // Name
    int hp;                 // Health point
    int damage;             // Attack damage
    int x;                  // X coordinate
    int y;                  // Y coordinate

    std::unique_ptr<AttackStrategy> attackStrategy; // Attack Strategy
};