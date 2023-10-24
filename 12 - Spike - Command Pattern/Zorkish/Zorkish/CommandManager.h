#pragma once
#include <unordered_map>
#include "Command.h"

class CommandManager {
private:
    std::unordered_map<std::string, Command*> commands;
public:
    void registerCommand(const std::string& name, Command* command);
    void executeCommand(const std::string& name, const std::string& argument);
};
    