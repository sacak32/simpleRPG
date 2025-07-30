#include <iostream>

#include "GameEngine.h"
#include "character/player/PlayerFactory.h"

GameEngine::GameEngine() {}

GameEngine& GameEngine::getInstance() {
    static GameEngine instance;
    return instance;
}

void GameEngine::run() {
    // Print welcome message
    std::cout << "Welcome to SimpleRPG\n";

    // Create the player
    createPlayer();

    // Create the enemy
    enemy = std::make_unique<Enemy>();

    // Add low health observer to enemy and player
    lowHealthObserver = std::make_unique<LowHealthObserver>();
    player->addObserver(lowHealthObserver.get());
    enemy->addObserver(lowHealthObserver.get());
    
    // Start the game
    playGame();
}

void GameEngine::createPlayer() {
    // Get player name
    std::string playerName;
    std::cout << "Enter name: ";
    std::getline(std::cin, playerName);

    // Get player class
    std::string playerClass;
    bool isValid;
    do {
        std::cout << "Enter class: ";
        std::getline(std::cin, playerClass);

        isValid = PlayerFactory::isValidClass(playerClass);
        if (!isValid)
            std::cout << "Invalid class!\n";
    } while (!isValid);

    // Create player
    player = PlayerFactory::create(playerName, playerClass);
}

void GameEngine::playGame() {
    // Read commands from user and process them. 
    std::string command;
    while (true) {
        std::cout << "Enter Command: ";
        std::getline(std::cin, command);

        if (!processCommand(command))
            break;
    }
}

bool GameEngine::processCommand(const std::string& command) {
    if (command == "h" || command == "help") {
        printHelp();
    } else if (command == "q" || command == "quit") {
        std::cout << "Quitting...\n";
        return false;
    } else if (command == "n" || command == "north") {
        player->move(0,1);
    } else if (command == "e" || command == "east") {
        player->move(1,0);
    } else if (command == "s" || command == "south") {
        player->move(0,-1);
    } else if (command == "w" || command == "west") {
        player->move(-1,0);
    } else if (command == "status") { 
        player->displayStatus();
    } else if (command == "attack") {
        bool isAlive = battle();
        if (!isAlive) return false;
    } else {
        std::cout << "Invalid command!\n";
    }
    return true;
}

void GameEngine::printHelp() const {
    std::cout << "Available commands:\n"
              << "h/help    : Print this message\n"
              << "q/quit    : Quit the game\n"
              << "n/north   : Move north\n"
              << "e/east    : Move east\n"
              << "s/south   : Move south\n"
              << "w/west    : Move west\n"
              << "status    : Display status\n"
              << "attack    : Performs an attack\n";
}

bool GameEngine::battle() {
    while (!player->isDead() && !enemy->isDead()) {
        player->attack(*enemy);
        if (enemy->isDead()) {
            std::cout << "Enemy is dead\n";
            break;
        }

        enemy->attack(*player);
        if (player->isDead()) {
            std::cout << "You are dead\n";
            return false;
        }
    }
    return true;
}