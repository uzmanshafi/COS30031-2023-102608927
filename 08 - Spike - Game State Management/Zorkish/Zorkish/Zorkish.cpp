// Zorkish.cpp
#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

int main() {
    StateManager manager;
    MainMenu mainMenu;

    manager.setState(&mainMenu);

    int choice;
    while (true) {
        std::cin >> choice;

        if (choice == 4)
            break;

        manager.handleInput(choice);
    }

    return 0;
}
