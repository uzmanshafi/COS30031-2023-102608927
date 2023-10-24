#include "CommandManager.h"
#include <string>
#include <iostream>

void CommandManager::registerCommand(const std::string& name, Command* command) {
    commands[name] = command;
}

void CommandManager::executeCommand(const std::string& name) {
    if (commands.find(name) != commands.end()) {
        commands[name]->execute();
    }
    else {
        // Command not found logic
        std::cout << "Invalid command: " << name << std::endl;
    }
}
