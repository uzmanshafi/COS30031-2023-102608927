#include "GameWorld.h"

GameWorld::GameWorld(json data) : _running(true)
{
	for (json loc : data["locations"])
	{
		_locations.push_back(new Location(loc));
	}

	Inventory* inv = new Inventory();

	_player = new Player(_locations.front(), inv);

	_commandManager = new CommandManager(_player);

	cout << "Welcome to Zorkish Adventure" << endl;
}

GameWorld::~GameWorld() {} 

Location* GameWorld::getLocation(string locName)
{
	for (Location* loc : _locations)
	{
		if (loc->getName() == locName)
			return loc;
	}

	return NULL;
}

vector<string> GameWorld::splitString(string input)
{
	vector<string> result;

	size_t pos = 0;
	string token;
	string delimiter = " ";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		result.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back(input);

	return result;
}

vector<string> GameWorld::processInput()
{
	string input;
	vector<string> commands;

	getline(cin, input);

	return splitString(input);
}


void GameWorld::movePlayer()
{
	_player->setLocation(getLocation(_player->getLocName()));
}

bool GameWorld::running()
{
	return _running;
}

void GameWorld::update()
{
	_commandManager->processCommand(processInput());
	movePlayer();
}

void GameWorld::render()
{
	Location* currentLocation = _player->getLocation();

	// Displays the description of the current location
	cout << currentLocation->getDesc() << endl;

	// Displays inventory items in the current location
	Inventory* currentInventory = currentLocation->getInventory();

	vector<Item*> items = currentInventory->getItems();
	if (!items.empty())
	{
		cout << "Item Found: " << endl;
		for (Item* item : items)
		{
			cout << "- " << item->getName() << " - " << item->getDesc() << endl;
		}
	}

	// Checks if the current location has any sublocations
	vector<Location*> sublocations = currentLocation->getSublocations();

	if (!sublocations.empty())
	{
		cout << "Available sublocations: " << endl;
		for (Location* sublocation : sublocations)
		{
			cout << "- " << sublocation->getName() << endl;
		}
	}

	cout << ">> ";
}
