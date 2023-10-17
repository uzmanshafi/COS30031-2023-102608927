#pragma once
#include "State.h"

class StateManager {
private:
    State* currentState;
    static StateManager* instance;

    StateManager();
    ~StateManager();

public:
    static StateManager* getInstance();

    void setState(State* state);
    void handleInput(int input);
    void changeState(State* newState);
};
