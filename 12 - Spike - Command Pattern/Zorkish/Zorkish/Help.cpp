#include "Help.h"
#include "MainMenu.h"
#include <iostream>

Help::Help(GameStateManager* mgr) : manager(mgr) {}

void Help::enter() {
    std::cout << "Zorkish :: Help\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "[go] _, (or just n, ne, e, etc)\n";
    std::cout << "look at _,\n";
    std::cout << "look in _,\n";
    std::cout << "inventory,\n";
    std::cout << "open _[with _],\n";
    std::cout << "close _,\n";
    std::cout << "attack _ with _\n";
    std::cout << "take _[from _]\n";
    std::cout << "put _ in _\n";
    std::cout << "drop _\n";
    std::cout << "quit\n";
    std::cout << "[up arrow] to repeat last command\n";
    std::cout << "Press Enter to return to the Main Menu\n";
}

void Help::update() {
    std::cin.get();
    manager->setGameState(new MainMenu(manager));
}

void Help::exit() {

}
