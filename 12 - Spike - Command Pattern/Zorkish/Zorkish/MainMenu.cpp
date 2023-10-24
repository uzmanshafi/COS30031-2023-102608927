#include "MainMenu.h"
#include "GameStateManager.h"
#include <iostream>
#include "About.h"
#include "Help.h"
#include "SelectAdventure.h"
#include "HallOfFame.h"

MainMenu::MainMenu(GameStateManager* mgr) : manager(mgr) {}

void MainMenu::enter() {
    std::cout << "Zorkish :: Main Menu\n";
    std::cout << "--------------------------------\n";
    std::cout << "1. Select Adventure and Play\n";
    std::cout << "2. Hall of Fame\n";
    std::cout << "3. Help\n";
    std::cout << "4. About\n";
    std::cout << "5. Quit\n";
    std::cout << "Select 1 - 5 : > ";
}

void MainMenu::update() {
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
        manager->setGameState(new SelectAdventure(manager));
        break;
    case 2:
        manager->setGameState(new HallOfFame(manager));
        break;
    case 3:
        manager->setGameState(new Help(manager));
        break;
    case 4:
        manager->setGameState(new About(manager));
        break;
    case 5:
        manager->setGameState(nullptr); // Exits the game
        break;
    default:
        std::cout << "Invalid choice. Try again.\n";
        break;
    }
}


void MainMenu::exit() {

}
