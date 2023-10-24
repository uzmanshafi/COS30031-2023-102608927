#include "Gameplay.h"
#include "StateManager.h"
#include "MainMenu.h"
#include "ViewHallOfFame.h"
#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

void Gameplay::initialize() {
    if (locations.empty()) {
        std::cout << "No locations to display." << std::endl;
        return;
    }
    currentLocationIndex = 0;
    std::cout << locations[currentLocationIndex].getName() << std::endl;
    std::cout << locations[currentLocationIndex].getDescription() << std::endl;
    std::cout << ":> ";
}


Gameplay::Gameplay() {
    currentLocationIndex = 0;
}

Gameplay::Gameplay(const std::vector<Location>& locs) : locations(locs) {}

void Gameplay::run() {}

void Gameplay::handleInput() {
    std::string command;
    std::getline(std::cin, command);

    if (command == "go") {
        currentLocationIndex = (currentLocationIndex + 1) % locations.size();
        std::cout << locations[currentLocationIndex].getName() << std::endl;
        std::cout << locations[currentLocationIndex].getDescription() << std::endl;
    }
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
