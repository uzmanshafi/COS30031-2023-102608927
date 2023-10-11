#include "Help.h"
#include "MainMenu.h"
#include "StateManager.h"
#include <iostream>

void Help::enter() {
    std::cout << "Zorkish :: Help" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "If this is phase 1 development show the following:" << std::endl;
    std::cout << "quit," << std::endl;
    std::cout << "hiscore (for testing)" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

void Help::handleInput(int input) {
    StateManager::getInstance()->changeState(new MainMenu());
}

void Help::exit() {
    std::cout << "Returning to Main Menu...\n";
}
