#include "NewHighScore.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>
#include <string>

void NewHighScore::initialize() {
    std::cout << "Zorkish :: New High Score" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Congratulations!" << std::endl;
    std::cout << "You have made it to the Zorkish Hall Of Fame" << std::endl;
    std::cout << "Please type your name and press enter:" << std::endl;
    std::cout << ":> ";
}

void NewHighScore::run() {}

void NewHighScore::handleInput() {
    std::string playerName;
    std::getline(std::cin, playerName);
    if (!playerName.empty()) {
        // Saves the playerName or do other processing.
        std::cout << "High score saved. Press Enter to return to the Main Menu..." << std::endl;
        std::cin.get();  // Waits for Enter key press
        StateManager::getInstance()->changeState(new MainMenu());
    }
    else {
        std::cout << "No name entered. Please type your name and press enter:" << std::endl;
    }
}

void NewHighScore::terminate() {
    std::cout << "Exiting New High Score...\n";
}
