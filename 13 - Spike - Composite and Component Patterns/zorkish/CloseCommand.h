#pragma once
#include "Command.h"
#include "Entity.h"

class CloseCommand : public Command {
public:
    virtual void execute(vector<string> args, Player* player) override;
};
