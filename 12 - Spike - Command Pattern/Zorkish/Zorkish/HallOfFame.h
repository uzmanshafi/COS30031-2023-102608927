#pragma once

#include "GameStateManager.h"
#include "State.h"

class HallOfFame : public State {
private:
    GameStateManager* manager;

public:
    HallOfFame(GameStateManager* mgr);
    void enter() override;
    void update() override;
    void exit() override;
};
