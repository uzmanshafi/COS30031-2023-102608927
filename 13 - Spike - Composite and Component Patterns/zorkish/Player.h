#pragma once
#include "Inventory.h"
#include "Location.h"
#include "Entity.h"

class Player
{
private:
    Inventory* _inventory;
    string _locName;
    Location* _location;
    int _health;

    Location* _currentSublocation;  // Supporting sublocations

public:
    Player(Location*, Inventory*);
    ~Player();

    int getHealth();
    void takeDamage(int);

    Inventory* getInventory();

    bool checkDirection(const string&);

    string getLocName();
    void setLocName(const string&);

    Location* getLocation();
    void setLocation(Location*);

    Entity* findEntityByName(const string& entityName);

    void enterSublocation(Location* subloc);
    void exitSublocation();
    Location* getCurrentLocation();

    bool isInSublocation() const { return _currentSublocation != nullptr; }  // Checks if the player is in a sublocation
};
