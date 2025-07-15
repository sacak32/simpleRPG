#pragma once

#include <string>

class Player {
public:
    // Constructor
    Player(const std::string& name, int hp, int mp);

    // Moves the player by dx and dy
    void move(int dx, int dy);

    // Prints out the status of player
    void displayStatus() const;

    // Performs the attack
    virtual void attack() = 0;

protected:
    std::string name;   // Name of the player

private:
    int hp;             // Health point of the player
    int mp;             // Mana point of the player
    int x;              // Horizontal coordinate of the player
    int y;              // Vertical coordinate of the player
};