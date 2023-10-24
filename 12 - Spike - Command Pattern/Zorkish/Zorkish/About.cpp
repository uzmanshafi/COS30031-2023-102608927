#include "About.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

void About::initialize() {
    std::cout << "Zorkish :: About" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Written by: Mohamed Shafi Uzman Fassy 102608927" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

void About::run() {
    //keeping empty for now.
}

void About::handleInput() {
    char c;
    std::cin.get(c);  // Captures the 'Enter' key press
    if (c == '\n') {
        StateManager::getInstance()->changeState(new MainMenu());
    }
}

void About::terminate() {
    std::cout << "Exiting About...\n";
}
