#include "NewHighScore.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

void NewHighScore::enter() {
    std::cout << "Zorkish :: New High Score" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Congratulations!" << std::endl;
    std::cout << "You have made it to the Zorkish Hall Of Fame" << std::endl;
    std::cout << "Adventure: [the adventure world played]" << std::endl; // Hard coded for phase 1. 
    std::cout << "Score: [the players score]" << std::endl; 
    std::cout << "Moves: [number of moves player made]" << std::endl; 
    std::cout << "Please type your name and press enter: " << std::endl;
}

void NewHighScore::handleInput(int input) {
    // For phase 1, the code just acknowledges the input and returns to the main menu.
    std::string playerName;
    std::cin >> playerName;
    std::cout << "Thank you, " << playerName << "! Your score has been recorded." << std::endl;
    StateManager::getInstance()->changeState(new MainMenu());
}

void NewHighScore::exit() {
    std::cout << "Exiting New High Score..." << std::endl;
}
