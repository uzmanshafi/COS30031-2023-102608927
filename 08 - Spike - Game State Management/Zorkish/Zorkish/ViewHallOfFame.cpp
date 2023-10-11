#include "ViewHallOfFame.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

void ViewHallOfFame::enter() {
    std::cout << "Zorkish :: Hall Of Fame" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Top 10 Zorkish Adventure Champions" << std::endl;
    // later I might load these dynamically, but I hard-code for phase 1.
    std::cout << "1. Fred, Mountain World, 5000" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

void ViewHallOfFame::handleInput(int input) {
    StateManager::getInstance()->changeState(new MainMenu());
}

void ViewHallOfFame::exit() {
    std::cout << "Exiting Hall of Fame..." << std::endl;
}
