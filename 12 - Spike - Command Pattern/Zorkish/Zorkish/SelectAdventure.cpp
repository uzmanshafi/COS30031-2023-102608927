#include "SelectAdventure.h"
#include "StateManager.h"
#include <iostream>

void SelectAdventure::initialize() {
    // ... (same as the enter method you provided)
}

void SelectAdventure::run() {}

void SelectAdventure::handleInput() {
    char input;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush newline from buffer
    switch (input) {
    case '1':
        std::cout << "You selected Mountain World." << std::endl;
        break;
    case '2':
        std::cout << "You selected Water World." << std::endl;
        break;
    case '3':
        std::cout << "You selected Box World." << std::endl;
        break;
    default:
        std::cout << "Invalid selection. Please select 1-3: ";
        break;
    }
}

void SelectAdventure::terminate() {
    std::cout << "Exiting Select Adventure...\n";
}
