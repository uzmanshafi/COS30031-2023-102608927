#include "ViewHallOfFame.h"
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

void ViewHallOfFame::initialize() {
    std::cout << "Zorkish :: Hall Of Fame" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Top 10 Zorkish Adventure Champions" << std::endl;
    std::cout << "1. Fred, Mountain World, 5000" << std::endl;
    std::cout << "2. Mary, Mountain World, 4000" << std::endl;
    std::cout << "3. Joe, Water World, 3000" << std::endl;
    std::cout << "4. Henry, Mountain World, 2000" << std::endl;
    std::cout << "5. Susan, Mountain World, 1000" << std::endl;
    std::cout << "6. Alfred, Water World, 900" << std::endl;
    std::cout << "7. Clark, Mountain World, 800" << std::endl;
    std::cout << "8. Harold, Mountain World, 500" << std::endl;
    std::cout << "9. Julie, Water World, 300" << std::endl;
    std::cout << "10. Bill, Box World, -5" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
    std::cout << ">";
}

void ViewHallOfFame::run() {}

void ViewHallOfFame::handleInput() {
    char c;
    std::cin.get(c);  // Captures the 'Enter' key press
    if (c == '\n') {
        StateManager::getInstance()->changeState(new MainMenu());
    }
}

void ViewHallOfFame::terminate() {
    std::cout << "Exiting Hall Of Fame...\n";
}