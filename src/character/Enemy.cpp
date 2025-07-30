#include <memory>

#include "character/Enemy.h"
#include "attackStrategy/AggressiveAttack.h"

Enemy::Enemy() 
    : Character("Enemy", 50, 3, 5, 5, std::make_unique<AggressiveAttack>()) {}