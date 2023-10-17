#include "StateManager.h"

StateManager* StateManager::instance = nullptr;

StateManager::StateManager() : currentState(nullptr) {}

StateManager* StateManager::getInstance() {
    if (!instance)
        instance = new StateManager();
    return instance;
}

StateManager::~StateManager() {
    if (currentState) {
        currentState->exit();
        delete currentState;
    }
}

void StateManager::setState(State* state) {
    if (currentState) {
        currentState->exit();
        delete currentState;
    }
    currentState = state;
    currentState->enter();
}

void StateManager::handleInput(int input) {
    if (currentState) {
        currentState->handleInput(input);
    }
}

void StateManager::changeState(State* newState) {
    setState(newState);
}
