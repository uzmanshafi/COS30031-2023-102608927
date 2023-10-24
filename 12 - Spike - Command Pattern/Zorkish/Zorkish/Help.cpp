#include "Help.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

void Help::initialize() {
    std::cout << "Zorkish :: Help" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "quit," << std::endl;
    std::cout << "hiscore (for testing)" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

void Help::run() {}

void Help::handleInput() {
    char c;
    std::cin.get(c);  // Captures the 'Enter' key press
    if (c == '\n') {
        StateManager::getInstance()->changeState(new MainMenu());
    }
}

void Help::terminate() {
    std::cout << "Exiting Help...\n";
}
