#pragma once
#include "State.h"

class GameStateManager;

class MainMenu : public State {
private:
    GameStateManager* manager;
public:
    MainMenu(GameStateManager* manager);
    void enter() override;
    void update() override;
    void exit() override;
};
