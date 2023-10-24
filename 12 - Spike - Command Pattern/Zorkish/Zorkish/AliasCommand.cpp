#include "AliasCommand.h"
#include <iostream>

std::unordered_map<std::string, std::string> AliasCommand::aliases;

void AliasCommand::execute() {
    std::cout << "Enter the alias you want to set: ";
    std::string alias;
    std::cin >> alias;

    std::cout << "Enter the command for this alias: ";
    std::string command;
    std::cin >> command;

    addAlias(alias, command);
    std::cout << "Alias set!" << std::endl;
}

void AliasCommand::addAlias(const std::string& alias, const std::string& command) {
    aliases[alias] = command;
}

std::string AliasCommand::resolveAlias(const std::string& input) {
    if (aliases.find(input) != aliases.end()) {
        return aliases[input];
    }
    return input; // returns the input unchanged if it's not an alias
}
