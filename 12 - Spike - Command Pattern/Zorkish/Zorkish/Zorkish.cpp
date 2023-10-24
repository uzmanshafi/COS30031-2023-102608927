#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

int main() {
    StateManager* manager = StateManager::getInstance();

    manager->changeState(new MainMenu());

    while (true) {
        manager->handleInput();
        // For later phases.
    }

    delete manager;
    return 0;
}
