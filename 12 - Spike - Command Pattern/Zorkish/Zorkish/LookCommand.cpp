#include "LookCommand.h"
#include <iostream>

LookCommand::LookCommand(Gameplay* gameInstance) : gameplay(gameInstance) {}

void LookCommand::execute() {
    std::cout << "You are in " << gameplay->getCurrentLocationName() << std::endl;
    std::cout << gameplay->getCurrentLocationDescription() << std::endl;
}