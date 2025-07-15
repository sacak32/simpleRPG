#pragma once

#include <memory>

#include "player/Player.h"

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

    std::unique_ptr<Player> player;     // The player
};