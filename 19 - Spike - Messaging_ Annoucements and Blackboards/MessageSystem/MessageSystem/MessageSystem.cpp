#include "Player.h"
#include "Chest.h"
#include "MessageDispatcher.h"
#include <iostream>

int main() {

    MessageDispatcher dispatcher;
    Player player("Player1", &dispatcher);
    Chest chest("Chest1", &dispatcher);

    // Registers player and chest with the dispatcher
    dispatcher.registerListener(player.getId(), [&player](const Message& message) {
        player.receiveMessage(message);
        });

    dispatcher.registerListener(chest.getId(), [&chest](const Message& message) {
        chest.receiveMessage(message);
        });

    // created an exmple to simulate player sending an "open" message to the chest
    Message openChestMessage(player.getId(), chest.getId(), "open", "");
    player.sendMessage(openChestMessage);

    return 0;
}
