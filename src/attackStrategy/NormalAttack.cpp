#include "attackStrategy/NormalAttack.h"
#include "Character.h"

void NormalAttack::attack(Character& source, Character& target) {
    target.applyDamage(source.getDamage());
}