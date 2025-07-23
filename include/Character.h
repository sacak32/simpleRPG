#pragma once

#include <memory>
#include <string>
#include <unordered_set>

#include "attackStrategy/AttackStrategy.h"
#include "observer/Observer.h"

class Character {
public:
    // Constructor
    Character(std::string name_, int hp_, int damage_, int x_, int y_, 
              std::unique_ptr<AttackStrategy> attackStrategy_);

    // Getter functions
    std::string getName() const { return name; }
    int getHp() const { return hp; }
    int getDamage() const { return damage; }

    // Prints out the status
    void displayStatus() const;

    // Performs the attack
    void attack(Character& character);

    // Is character dead?
    bool isDead() const;

    // Applies the given damage
    void applyDamage(int damage);

    // Observer functions
    void notifyObservers(const std::string& event);
    void addObserver(Observer* observer) { observers.insert(observer); }
    void removeObserver(Observer* observer) { observers.erase(observer); }

protected:
    std::string name;       // Name
    int hp;                 // Health point
    int damage;             // Attack damage
    int x;                  // X coordinate
    int y;                  // Y coordinate

    std::unique_ptr<AttackStrategy> attackStrategy; // Attack Strategy
    std::unordered_set<Observer*> observers;        // Observers
};