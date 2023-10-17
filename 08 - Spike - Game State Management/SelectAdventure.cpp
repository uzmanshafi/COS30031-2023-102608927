// SelectAdventure.cpp
#include "SelectAdventure.h"
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


void SelectAdventure::exit() 
{
    std::cout << "Exiting Select Adventure..." << std::endl;
}

void SelectAdventure::handleInput(int input) {
    switch (input) {
    case '1':
        std::cout << "You selected Mountain World." << std::endl;
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
