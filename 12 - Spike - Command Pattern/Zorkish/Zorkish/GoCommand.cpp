#include "GoCommand.h"
#include <iostream>

GoCommand::GoCommand(Gameplay* gameInstance) : gameplay(gameInstance) {}

void GoCommand::execute() {
    gameplay->moveToNextLocation();
    std::cout << "Changed location to: " << gameplay->getCurrentLocationName() << std::endl;
}