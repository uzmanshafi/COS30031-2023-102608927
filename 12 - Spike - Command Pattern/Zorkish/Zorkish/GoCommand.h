#pragma once
#include "Command.h"
#include "Gameplay.h" 

class GoCommand : public Command {
private:
    Gameplay* gameplay;
public:
    GoCommand(Gameplay* gameInstance);
    void execute() override;
};