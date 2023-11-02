#include "Chest.h"
#include <iostream>

void Chest::receiveMessage(const Message& message) {
    if (message.kind == "open") {
        bool isLocked = false;  // just a placeholder for chest locked state
        std::string item = "Golden Apple";  // just a placeholder for the item inside the chest

        // Checks if the chest is locked
        if (!isLocked) {
            std::cout << getId() << " has been opened by " << message.from << "." << std::endl;

            // If chest is unlocked, it will send an "itemReceived" message back to the sender (player)
            Message itemMessage(getId(), message.from, "itemReceived", item);
            sendMessage(itemMessage);
        }
        else {
            // If the chest is locked, it will send a message back or handle it otherwise.
            std::cout << getId() << " is locked and cannot be opened by " << message.from << "." << std::endl;
        }
    }
}
