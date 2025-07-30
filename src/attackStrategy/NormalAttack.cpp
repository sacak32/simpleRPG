#include "attackStrategy/NormalAttack.h"
#include "character/Character.h"

void NormalAttack::attack(Character& source, Character& target) {
    target.applyDamage(source.getDamage());
}