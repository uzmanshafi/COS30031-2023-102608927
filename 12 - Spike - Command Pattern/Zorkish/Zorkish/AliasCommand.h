#pragma once
#include "Command.h"
#include <unordered_map>
#include <string>


class AliasCommand : public Command {
public:
    void execute() override;

    // This function allows adding an alias to the command
    static void addAlias(const std::string& alias, const std::string& command);

    // This function checks if the given input is an alias and returns the associated command
    static std::string resolveAlias(const std::string& input);

private:
    static std::unordered_map<std::string, std::string> aliases; // map alias to actual command
};
