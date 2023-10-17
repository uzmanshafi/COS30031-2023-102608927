#pragma once
#include "State.h"

class StateManager {
private:
    State* currentState;
    static StateManager* instance;

    StateManager();

public:
    ~StateManager();

    static StateManager* getInstance();
    void changeState(State* newState);
    void handleInput();
};
