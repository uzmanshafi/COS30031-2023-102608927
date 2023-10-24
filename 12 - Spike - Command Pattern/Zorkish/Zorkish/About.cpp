#include "About.h"
#include "MainMenu.h"
#include <iostream>

About::About(GameStateManager* mgr) : manager(mgr) {}

void About::enter() {
    std::cout << "Zorkish :: About\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Written by: Mohamed Shafi Uzman\n";
    std::cout << "Press Enter to return to the Main Menu\n";
}

void About::update() {
    std::cin.get();
    manager->setGameState(new MainMenu(manager));
}

void About::exit() {

}