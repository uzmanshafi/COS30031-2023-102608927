#include "Inventory.h"
#include <iostream>

void Inventory::add(const Item& item) {
    items.push_back(item);
}

void Inventory::remove(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
        [&itemName](const Item& item) {
            return item.getName() == itemName;
        }), items.end());
}

void Inventory::view() const {
    std::cout << "Items in Inventory: " << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item.getName() << std::endl;
    }
}
