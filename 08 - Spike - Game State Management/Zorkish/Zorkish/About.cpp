#include "StateManager.h"
#include "MainMenu.h"
#include "About.h"
#include <iostream>

void About::enter() {
    std::cout << "Zorkish :: About" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Written by: [your name here]" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

void About::handleInput(int input) {
    StateManager::getInstance()->changeState(new MainMenu());

}

void About::exit() {
    std::cout << "Returning to Main Menu...\n";
}
