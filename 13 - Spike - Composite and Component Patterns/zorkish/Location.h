#pragma once

#include <string>
#include <map>
#include <vector>
#include "json.hpp"
#include "Inventory.h"
#include "Entity.h"

// Forward declaration
class Item;

using json = nlohmann::json;

class Location
{
private:
    // Attributes
    string _name;
    string _desc;
    map<string, string> _connections;
    Inventory _inventory;

    // Sublocations
    vector<Location*> _sublocations;

    // Entities
    vector<Entity*> _entities;

public:
    // Constructors & Destructor
    Location(json data);
    ~Location();

    // Descriptors
    string getName() const;
    string getDesc() const;

    // Connection management
    string findConnection(const string& direction);
    void showConnections();

    // Inventory management
    bool findItem(const string& itemName);
    void viewItems();
    bool addItem(Item* item);
    bool removeItem(const string& itemName);
    Item* getItem(const string& itemName);
    Inventory* getInventory();

    // Sublocation management
    Location* findSublocation(const string& sublocationName);
    vector<Location*> getSublocations() const;

    // Entity management
    Entity* findEntityByName(const string& entityName);
    vector<Entity*> getEntities() const;
    vector<string> getEntityDescriptions() const;

};
