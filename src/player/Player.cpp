#include <iostream>

#include "player/Player.h"

Player::Player(const std::string& _name, int _hp, int _mp) 
    : name(_name), hp(_hp), mp(_mp), x(0), y(0) {}

// Moves the player by dx and dy
void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
    std::cout << name << " moves to (" << x << ", " << y << ")\n";
}

// Prints out the status of player
void Player::displayStatus() const {
    std::cout << "HP: " << hp
              << ", MP: " << mp
              << ", Position: (" << x << ", " << y << ")\n";
}               