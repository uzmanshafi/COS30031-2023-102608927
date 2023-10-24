#include "CommandManager.h"
#include "AliasCommand.h" 
#include <string>
#include <iostream>

CommandManager* CommandManager::instance = nullptr;

CommandManager* CommandManager::getInstance() {
    if (!instance) {
        instance = new CommandManager();
    }
    return instance;
}


void CommandManager::registerCommand(const std::string& name, Command* command) {
    commands[name] = command;
}

void CommandManager::executeCommand(const std::string& name) {
    // Resolves if the input is an alias
    std::string resolvedCommand = AliasCommand::resolveAlias(name);

    if (commands.find(resolvedCommand) != commands.end()) {
        commands[resolvedCommand]->execute();
    }
    else {
        // Command not found logic
        std::cout << "Invalid command: " << name << std::endl;
    }
}
