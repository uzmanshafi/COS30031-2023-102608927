#include "SelectAdventure.h"
#include "MainMenu.h"
#include "StateManager.h"
#include <iostream>

void SelectAdventure::enter() {
    std::cout << "Zorkish :: Select Adventure" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Choose your adventure:" << std::endl;
    std::cout << "1. Mountain World" << std::endl;
    std::cout << "2. Water World" << std::endl;
    std::cout << "3. Box World" << std::endl;
    std::cout << "Select 1-3:> ";
}

void SelectAdventure::handleInput(int input) {
    // For phase 1, I just print a message and then revert back to main menu.
    // Ideally, this would later transition into the gameplay state for the selected adventure.
    switch (input) {
    case 1:
        std::cout << "Mountain World selected!" << std::endl;
        break;
    case 2:
        std::cout << "Water World selected!" << std::endl;
        break;
    case 3:
        std::cout << "Box World selected!" << std::endl;
        break;
    default:
        std::cout << "Invalid selection. Please select 1-3: ";
        break;
    }
    // For now, simply revert back to the main menu.
    StateManager::getInstance()->changeState(new MainMenu());
}

void SelectAdventure::exit() {

    std::cout << "Exiting Select Adventure..." << std::endl;
}
