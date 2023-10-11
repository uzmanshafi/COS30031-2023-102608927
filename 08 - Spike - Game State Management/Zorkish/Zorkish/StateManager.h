
#pragma once
#include "State.h"

class StateManager {
private:
    State* currentState;
public:
    StateManager();
    ~StateManager();

    void setState(State* state);
    void handleInput(int input);
};
