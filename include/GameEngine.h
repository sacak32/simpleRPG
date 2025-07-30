#pragma once

#include <memory>

#include "character/player/Player.h"
#include "character/Enemy.h"
#include "observer/LowHealthObserver.h"

/* Represents the game engine. Created as Singleton */
class GameEngine {
public:
    // Returns the single GameEngine instance
    static GameEngine& getInstance();

    // Runs the game engine
    void run();

    // Delete copy/move constructors to enforce Singleton
    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;
    GameEngine(GameEngine&&) = delete;
    GameEngine& operator=(GameEngine&&) = delete;
private:
    // Constructor
    GameEngine();

    // Creates the player with user choices
    void createPlayer();
    
    // The actual gameplay, called after initialization 
    void playGame();

    // Processes the command given by the user. Returns true if the game should continue.
    bool processCommand(const std::string& command);

    // Prints the available commands
    void printHelp() const;

    // Simulates the battle between player and enemy, returns is the player is alive after the battle.
    bool battle();

    std::unique_ptr<Player> player;     // The player
    std::unique_ptr<Enemy> enemy;       // The enemy

    std::unique_ptr<LowHealthObserver> lowHealthObserver;
};