#include "Gameplay.h"
#include "StateManager.h"
#include "MainMenu.h"
#include "ViewHallOfFame.h"
#include <iostream>
#include <string>

void Gameplay::initialize() {
    std::cout << "Welcome to Zorkish: Void World" << std::endl;
    std::cout << "This world is simple and pointless. Used it to test Zorkish phase 1 spec." << std::endl;
    std::cout << ":> ";
}

void Gameplay::run() {
    // For future phases: gameplay logic, updates, animations etc.
}

void Gameplay::handleInput() {
    std::string command;
    std::getline(std::cin, command);

    if (command == "quit") {
        std::cout << "Your adventure has ended without fame or fortune." << std::endl;
        StateManager::getInstance()->changeState(new MainMenu());
    }
    else if (command == "hiscore") {
        std::cout << "You have entered the magic word and will now see the “New High Score” screen." << std::endl;
        StateManager::getInstance()->changeState(new ViewHallOfFame());
    }
    else {
        std::cout << "Invalid command. Please enter a valid command." << std::endl;
        std::cout << ":> ";
    }
}

void Gameplay::terminate() {
    std::cout << "Exiting Gameplay...\n";
}
