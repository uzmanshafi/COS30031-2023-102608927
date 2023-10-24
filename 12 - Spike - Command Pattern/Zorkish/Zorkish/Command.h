#pragma once
#include <string>

class Command {
public:
    virtual void execute(const std::string& argument) = 0;
};
