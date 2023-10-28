#pragma once
#include "Command.h"
#include "Entity.h"

class OpenCommand : public Command {
public:
    virtual void execute(vector<string> args, Player* player) override;
};
