#pragma once
#include "State.h"

class MainMenu : public State {
public:
    void initialize() override;
    void run() override; 
    void terminate() override;
    void handleInput() override;
};
