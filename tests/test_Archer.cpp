#include <gtest/gtest.h>
#include "character/player/Archer.h"

// Define ArcherTest
class ArcherTest : public ::testing::Test {
protected:
    // Common test data
    Archer archer{"Conan"};

    // Setup
    void SetUp() override {
        archer.move(0,0);
    }

    void TearDown() override {}
};

// Test Archer initialization
TEST_F(ArcherTest, ArcherInitialName) {
    EXPECT_EQ(archer.getHp(), 100); 
    EXPECT_EQ(archer.getName(), "Conan");
}

// Test Archer movement
TEST_F(ArcherTest, ArcherApplyDamage) {
    archer.applyDamage(30);
    EXPECT_EQ(archer.getHp(), 70); 
}