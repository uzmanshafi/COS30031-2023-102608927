#pragma once
#include "State.h"

class Help : public State {
public:
    void enter() override;
    void exit() override;
    void handleInput(int input) override;
};
