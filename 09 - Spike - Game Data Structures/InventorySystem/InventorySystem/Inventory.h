#pragma once
#include "Item.h"
#include <vector>
#include <algorithm>

class Inventory {
private:
    std::vector<Item> items;

public:
    void add(const Item& item);
    void remove(const std::string& itemName);
    void view() const;
};
