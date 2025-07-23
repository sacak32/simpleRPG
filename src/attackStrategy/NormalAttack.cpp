#include "attackStrategy/NormalAttack.h"

void NormalAttack::attack(Character& source, Character& target) {
    target.applyDamage(source.getDamage());
}