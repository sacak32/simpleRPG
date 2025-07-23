#include <memory>

#include "Enemy.h"
#include "attackStrategy/AggressiveAttack.h"

Enemy::Enemy() 
    : Character("Enemy", 50, 3, 5, 5, std::make_unique<AggressiveAttack>()) {}