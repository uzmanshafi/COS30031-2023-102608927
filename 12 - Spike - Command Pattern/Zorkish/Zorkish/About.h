#pragma once

#include "GameStateManager.h"
#include "State.h"

class About : public State {
private:
    GameStateManager* manager;

public:
    About(GameStateManager* mgr);
    void enter() override;
    void update() override;
    void exit() override;
};
