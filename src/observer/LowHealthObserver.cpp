#include <iostream>

#include "observer/LowHealthObserver.h"
#include "character/Character.h"

void LowHealthObserver::onNotify(const Character& character, const std::string& event) {
    if (event == "HP_CHANGED" && character.getHp() < 0)
        std::cout << character.getName() << "'s HP is below 0." << std::endl;
}