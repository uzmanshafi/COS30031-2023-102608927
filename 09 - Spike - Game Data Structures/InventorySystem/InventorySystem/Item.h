#pragma once
#include <string>

class Item {
private:
    std::string name;

public:
    Item(const std::string& itemName) : name(itemName) {}
    std::string getName() const { return name; }
};
