#include "CommandManager.h"

void CommandManager::registerCommand(const std::string& name, Command* command) {
    commands[name] = command;
}

void CommandManager::executeCommand(const std::string& name, const std::string& argument) {
    if (commands.find(name) != commands.end()) {
        commands[name]->execute(argument);
    }
}
