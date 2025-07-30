#include <gtest/gtest.h>
#include "character/player/Warrior.h"

// Test Warrior initialization
TEST(WarriorTest, WarriorInitialHealth) {
    Warrior w("Conan");
    EXPECT_EQ(w.getHp(), 150);  // assuming Warrior starts with 150 health
    EXPECT_EQ(w.getName(), "Conan");
}