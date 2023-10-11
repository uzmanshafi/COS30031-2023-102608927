#pragma once
#include "State.h"

class Help : public State {
public:
    void enter() override;
    void handleInput(int input) override;
    void exit() override;
};
