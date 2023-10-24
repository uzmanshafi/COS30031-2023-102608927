#include "SelectAdventure.h"
#include "StateManager.h"
#include <iostream>
#include "GameWorldLoader.h"
#include "Gameplay.h"
#include "json.hpp"
using json = nlohmann::json;


void SelectAdventure::initialize() {

}

void SelectAdventure::run() {}

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
        break;
    case '3':
        std::cout << "You selected Box World." << std::endl;
        break;
    default:
        std::cout << "Invalid selection. Please select 1-3: ";
        break;
    }
}

void SelectAdventure::loadAdventure(const std::string& filename) {
    // Loads the adventure here
    auto locations = GameWorldLoader::LoadLocations(filename);

    // For now, it just print the loaded locations (for debugging)
    for (const auto& location : locations) {
        std::cout << "Loaded Location: " << location.getName() << " - " << location.getDescription() << std::endl;
    }

    // Passes the loaded locations to Gameplay
    StateManager::getInstance()->changeState(new Gameplay(locations));
}


void SelectAdventure::terminate() {
    std::cout << "Exiting Select Adventure...\n";
}
