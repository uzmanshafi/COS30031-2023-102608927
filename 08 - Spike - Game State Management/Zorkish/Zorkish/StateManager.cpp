#include "StateManager.h"

StateManager* StateManager::instance = nullptr;

StateManager::StateManager() : currentState(nullptr) {}

StateManager::~StateManager() {
    if (currentState) {
        currentState->terminate();
        delete currentState;
    }
}

StateManager* StateManager::getInstance() {
    if (!instance)
        instance = new StateManager();
    return instance;
}

void StateManager::changeState(State* newState) {
    if (currentState) {
        currentState->terminate();
        delete currentState;
    }
    currentState = newState;
    currentState->initialize();
}

void StateManager::handleInput() {
    if (currentState) {
        currentState->handleInput();
    }
}
