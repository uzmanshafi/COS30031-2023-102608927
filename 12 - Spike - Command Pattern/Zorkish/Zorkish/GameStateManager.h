#pragma once
#include "State.h"

class GameStateManager {
private:
    State* currentState;
public:
    GameStateManager();
    ~GameStateManager();
    void run();
    void setGameState(State* state);
};
