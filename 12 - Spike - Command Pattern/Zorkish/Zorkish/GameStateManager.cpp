#include "GameStateManager.h"
#include "MainMenu.h"

GameStateManager::GameStateManager() : currentState(new MainMenu(this)) {}

GameStateManager::~GameStateManager() {
    delete currentState;
}

void GameStateManager::run() {
    while (currentState) {
        currentState->enter();
        currentState->update();
        currentState->exit();
    }
}

void GameStateManager::setGameState(State* state) {
    delete currentState;
    currentState = state;
}
