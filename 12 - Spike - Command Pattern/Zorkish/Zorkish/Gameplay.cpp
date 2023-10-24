#include "Gameplay.h"
#include "MainMenu.h"
#include "HighScore.h"
#include <iostream>
#include <string>

Gameplay::Gameplay(GameStateManager* mgr) : manager(mgr) {}

void Gameplay::enter() {
    std::cout << "Welcome to Zorkish: Void World\n";
    std::cout << "This world is simple and pointless. Used it to test Zorkish phase 1 spec.\n";
    std::cout << ":> ";
}

void Gameplay::update() {
    std::string command;
    std::getline(std::cin, command);

    if (command == "quit") {
        std::cout << "Your adventure has ended without fame or fortune.\n";
        manager->setGameState(new MainMenu(manager)); // transitions to Main Menu
    }
    else if (command == "hiscore") {
        std::cout << "You have entered the magic word and will now see the “New High Score” screen.\n";
        // Transitions to the New High Score screen here
        manager->setGameState(new HighScore(manager));
    }
    else {
        std::cout << "Invalid command. Try 'quit' or 'hiscore'.\n";
        std::cout << ":> ";
    }
}

void Gameplay::exit() {
    // Cleanup or reset any gameplay data here if necessary
}
