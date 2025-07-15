#include "GameEngine.h"

int main() {
    GameEngine& engine = GameEngine::getInstance();
    engine.run();
    return 0;
}