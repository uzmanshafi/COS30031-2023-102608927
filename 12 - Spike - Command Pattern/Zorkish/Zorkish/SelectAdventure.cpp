#include "SelectAdventure.h"
#include "StateManager.h"
#include <iostream>
#include "GameWorldLoader.h"
#include "Gameplay.h"
#include "json.hpp"
using json = nlohmann::json;


void SelectAdventure::initialize() {
    std::cout << "Zorkish :: Select Adventure\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Choose your adventure:\n";
    std::cout << "1. Mountain World\n";
    std::cout << "2. Water World\n";
    std::cout << "3. Box World\n";
    std::cout << "Select 1-3:> ";
}

void SelectAdventure::run() {
    handleInput();
}

void SelectAdventure::handleInput() {
    char input;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush newline from buffer
    switch (input) {
    case '1':
        std::cout << "You selected Mountain World." << std::endl;
        loadAdventure("adventure.json");
        StateManager::getInstance()->changeState(new Gameplay()); 
        break;
    case '2':
        std::cout << "You selected Water World." << std::endl;
        loadAdventure("adventure.json");
        StateManager::getInstance()->changeState(new Gameplay());
        break;
    case '3':
        std::cout << "You selected Box World." << std::endl;
        loadAdventure("adventure.json");
        StateManager::getInstance()->changeState(new Gameplay());
        break;
    default:
        std::cout << "Invalid selection. Please select 1-3: ";
        break;
    }
}

void SelectAdventure::loadAdventure(const std::string& filename) {
    // Loads the adventure here
    auto locations = GameWorldLoader::LoadLocations(filename);

    // Passes the loaded locations to Gameplay
    StateManager::getInstance()->changeState(new Gameplay(locations));
}


void SelectAdventure::terminate() {
    std::cout << "Exiting Select Adventure...\n";
}
