#pragma once
#include "State.h"

class MainMenu : public State {
public:
    void enter() override;
    void exit() override;
    void handleInput(int input) override;
};
