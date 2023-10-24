#pragma once

#include "GameStateManager.h"
#include "State.h"

class HighScore : public State {
private:
    GameStateManager* manager;

public:
    HighScore(GameStateManager* mgr);
    void enter() override;
    void update() override;
    void exit() override;
};
