#include "SelectAdventure.h"
#include "MainMenu.h"
#include <iostream>

SelectAdventure::SelectAdventure(GameStateManager* mgr) : manager(mgr) {}

void SelectAdventure::enter() {
    std::cout << "Zorkish :: Select Adventure\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Choose your adventure :\n";
    std::cout << "1. Mountain World\n";
    std::cout << "2. Water World\n";
    std::cout << "3. Box World\n";
    std::cout << "Select 1 - 3 : >\n";
}

void SelectAdventure::update() {
    std::cin.get();
    manager->setGameState(new MainMenu(manager));
}

void SelectAdventure::exit() {

}
