#pragma once
#include "Command.h"
#include "Gameplay.h" 

class LookCommand : public Command {
private:
    Gameplay* gameplay;
public:
    LookCommand(Gameplay* gameInstance);
    void execute() override;
};