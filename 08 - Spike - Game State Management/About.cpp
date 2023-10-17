#include "About.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

void About::enter() {
    std::cout << "Zorkish :: About" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Written by: Mohamed Shafi Uzman Fassy" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

void About::handleInput(int input) {
    char c;
    std::cin.get(c);  // Captures the 'Enter' key press
    StateManager::getInstance()->changeState(new MainMenu());
}

void About::exit() {
    std::cout << "Exiting About...\n";
}
