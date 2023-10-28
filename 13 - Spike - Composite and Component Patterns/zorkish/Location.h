#pragma once
#include <string>
#include <map>
#include "json.hpp"
#include "Inventory.h"
#include <vector>
#include "Entity.h"

using json = nlohmann::json;
using namespace std;

class Location
{
private:
	string _name;
	string _desc;
	map<string, string> _connections;
	Inventory _inventory;

	//creating a sublocation for task 13
	vector<Location*> _sublocations;

	vector<Entity*> _entities;
public:
	Location(json);
	~Location();

	//Descriptors
	string getName() const;
	string getDesc() const;

	//Connections
	string findConnection(const string&);
	void showConnections();

	//Inventory interface
	bool findItem(const string&);
	void viewItems();
	bool addItem(Item*);
	bool removeItem(const string&);
	Item* getItem(const string&);
	Inventory* getInventory();

	//sublocations for  task 13
	Location* findSublocation(const string& name);

	//returns the sublocations
	vector<Location*> getSublocations() const;

	Entity* findEntityByName(const string& entityName);
};
