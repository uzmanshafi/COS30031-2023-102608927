#pragma once

#include "GameStateManager.h"
#include "State.h"

class Help : public State {
private:
    GameStateManager* manager;

public:
    Help(GameStateManager* mgr);
    void enter() override;
    void update() override;
    void exit() override;
};
