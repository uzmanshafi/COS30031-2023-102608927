#include "MainMenu.h"
#include "StateManager.h"
#include <iostream>

void MainMenu::enter() {
    std::cout << "Zorkish :: Main Menu" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Welcome to Zorkish Adventures" << std::endl;
    std::cout << "1. Select Adventure and Play" << std::endl;
    std::cout << "2. Hall Of Fame" << std::endl;
    std::cout << "3. Help" << std::endl;
    std::cout << "4. About" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << "Select 1-5:> ";
}

void MainMenu::exit() {
    std::cout << "Exiting Main Menu...\n";
}

void MainMenu::handleInput(int input) {
    switch (input) {
        
    }
}
