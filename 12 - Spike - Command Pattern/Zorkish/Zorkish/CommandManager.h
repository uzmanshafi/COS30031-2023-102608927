#pragma once
#include "Command.h"
#include <string>
#include <unordered_map>

class CommandManager {
public:
    static CommandManager* getInstance();  
    void registerCommand(const std::string& name, Command* command);
    void executeCommand(const std::string& name);

private:
    CommandManager() = default;  
    static CommandManager* instance;  
    std::unordered_map<std::string, Command*> commands;
};
