#include "MainMenu.h"
#include "StateManager.h"
#include "SelectAdventure.h"
#include "Help.h"
#include "About.h"
#include "ViewHallOfFame.h"
#include <iostream>

void MainMenu::initialize() {
    // Display the menu as usual
    std::cout << "Zorkish :: Main Menu" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Welcome to Zorkish Adventures" << std::endl;
    std::cout << "1. Select Adventure and Play" << std::endl;
    std::cout << "2. Hall Of Fame" << std::endl;
    std::cout << "3. Help" << std::endl;
    std::cout << "4. About" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << "Select 1-5:> ";
}

void MainMenu::run() {
    //empty
}

void MainMenu::terminate() {
    std::cout << "Exiting Main Menu...\n";
}

void MainMenu::handleInput() {
    int input;
    std::cin >> input;
    switch (input) {
    case 1:
        StateManager::getInstance()->changeState(new SelectAdventure());
        break;
    case 2:
        StateManager::getInstance()->changeState(new ViewHallOfFame());
        break;
    case 3:
        StateManager::getInstance()->changeState(new Help());
        break;
    case 4:
        StateManager::getInstance()->changeState(new About());
        break;
    case 5:
        terminate();
        exit(0); // Exits the program for now
        break;
    default:
        std::cout << "Invalid selection. Please select 1-5: ";
        break;
    }
}
