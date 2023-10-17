// NewHighScore.cpp
#include "NewHighScore.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

void NewHighScore::enter() {
    std::cout << "Zorkish :: New High Score" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Congratulations!" << std::endl;
    std::cout << "You have made it to the Zorkish Hall Of Fame" << std::endl;
    std::cout << "Please type your name and press enter:" << std::endl;
    std::cout << ":> ";
}

void NewHighScore::exit() {
    std::cout << "Exiting New High Score..." << std::endl;
}

void NewHighScore::handleInput(int input) {
    if (input == '\n') {
        // Does not work current during Phase 1, later will be coding it work.
        std::cout << "High score saved. Press Enter to return to the Main Menu..." << std::endl;
        std::cin.get(); // Waits for Enter key press
        StateManager::getInstance()->changeState(new MainMenu());
    }
}
