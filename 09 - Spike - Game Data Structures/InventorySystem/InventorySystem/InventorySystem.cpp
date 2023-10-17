#include "Inventory.h"
#include <iostream>

int main() {
    Inventory playerInventory;
    Item sword("Sword");
    Item shield("Shield");
    Item potion("Potion");

    playerInventory.add(sword);
    playerInventory.add(shield);
    playerInventory.add(potion);

    playerInventory.view();

    playerInventory.remove("Potion");
    std::cout << "\nAfter removing potion:" << std::endl;
    playerInventory.view();

    return 0;
}
