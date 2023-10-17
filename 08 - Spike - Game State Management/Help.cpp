#include "Help.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

void Help::enter()
{
    std::cout << "Zorkish :: Help" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "The following commands are supported:" << std::endl;;
    std::cout << "quit," << std::endl;
    std::cout << "hiscore (for testing)" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

void Help::exit()
{
    std::cout << "Exiting Help...\n";
}

void Help::handleInput(int input) {
    // Handles the Enter key press to return to the Main Menu
    if (input == '\n') {
        StateManager::getInstance()->changeState(new MainMenu());
    }
}
