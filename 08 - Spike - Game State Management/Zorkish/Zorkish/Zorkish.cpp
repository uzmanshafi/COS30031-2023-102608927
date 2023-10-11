#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

int main() {

    StateManager* manager = StateManager::getInstance();

    manager->setState(new MainMenu());

    int choice;
    while (true) {
        std::cin >> choice;

        if (choice == 5)
            break;

        manager->handleInput(choice);
    }

    return 0;
}
