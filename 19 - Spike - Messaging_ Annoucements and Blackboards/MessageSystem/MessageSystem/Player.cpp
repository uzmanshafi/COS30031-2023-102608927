#include "Player.h"
#include <iostream>

void Player::receiveMessage(const Message& message) {
    if (message.kind == "open")
    {
        bool isLocked = false; //I did this just to simply, if player is near a door he can go out
        if (isLocked)
        {
            std::cout << "Player" << id << "opened a chest" << message.to << std::endl;
        }
        else
        {
            std::cout << "Player" << id << "cant open chest because it is locked" << message.to << std::endl;
        }
    }
    else if (message.kind == "itemReceived") {
        std::cout << id << " received item: " << message.data << std::endl;
        // if I wanted to make it complicated I would have created an inventory system and add an item to the player's inventory.
    }
    else {
        std::cout << id << " received an unknown message type." << std::endl;
    }
}
