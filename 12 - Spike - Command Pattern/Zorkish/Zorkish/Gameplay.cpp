#include "Gameplay.h"
#include "StateManager.h"
#include "MainMenu.h"
#include "ViewHallOfFame.h"
#include <iostream>
#include <string>
#include "json.hpp"
#include "CommandManager.h"

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

void Gameplay::run() {
    while (true) {
        handleInput();
    }
}

void Gameplay::handleInput() {
    std::string command;
    std::getline(std::cin, command);
    CommandManager* cmdManager = CommandManager::getInstance();
    cmdManager->executeCommand(command);
}

void Gameplay::moveToNextLocation() {
    currentLocationIndex = (currentLocationIndex + 1) % locations.size();
    std::cout << locations[currentLocationIndex].getName() << std::endl;
    std::cout << locations[currentLocationIndex].getDescription() << std::endl;
}

std::string Gameplay::getCurrentLocationName() {
    return locations[currentLocationIndex].getName();
}

std::string Gameplay::getCurrentLocationDescription() {
    return locations[currentLocationIndex].getDescription();
}

void Gameplay::terminate() {
    std::cout << "Exiting Gameplay...\n";
}