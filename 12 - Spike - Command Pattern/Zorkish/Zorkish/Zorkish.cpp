#include "StateManager.h"
#include "MainMenu.h"
#include <iostream>

int main() {
    StateManager* manager = StateManager::getInstance();

    manager->changeState(new MainMenu());

    while (true) {
        manager->handleInput();
        
    }

    delete manager;
    return 0;
}
