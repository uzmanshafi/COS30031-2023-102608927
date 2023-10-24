#pragma once

#include "GameStateManager.h"
#include "State.h"

class Gameplay : public State {
private:
    GameStateManager* manager;

public:
    Gameplay(GameStateManager* mgr);
    void enter() override;
    void update() override;
    void exit() override;
};
