#include <iostream>

#include "player/PlayerFactory.h"
#include "player/Warrior.h"
#include "player/Mage.h"
#include "player/Archer.h"

bool PlayerFactory::isValidClass(const std::string& playerClass) {
    return  playerClass == "warrior" ||
            playerClass == "mage" ||
            playerClass == "archer";
}

std::unique_ptr<Player> PlayerFactory::create(const std::string& playerName, const std::string& playerClass) {
    if (playerClass == "warrior")
        return std::make_unique<Warrior>(playerName);
    else if (playerClass == "mage")
        return std::make_unique<Mage>(playerName);
    else if (playerClass == "archer")
        return std::make_unique<Archer>(playerName);
    else
        std::cerr << "Error: Invalid class!\n";
    return nullptr;
}