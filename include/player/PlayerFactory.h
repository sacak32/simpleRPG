#pragma once

#include <memory>
#include <string>

#include "player/Player.h"

class PlayerFactory {
public:
    // Checks if the given class name is valid
    static bool isValidClass(const std::string& playerClass);

    // Creates the player with given inputs
    static std::unique_ptr<Player> create(const std::string& playerName, const std::string& playerClass);
};