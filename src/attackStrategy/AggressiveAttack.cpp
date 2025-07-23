#include "attackStrategy/AggressiveAttack.h"
#include "Character.h"

void AggressiveAttack::attack(Character& source, Character& target) {
    int damage = source.getDamage();
    target.applyDamage(2*damage);
    source.applyDamage(damage);
}