#include "Player.h"
#include "Entity.h"

Player::Player(Location* loc, Inventory* inv) : _location(loc), _inventory(inv), _health(100)
{
	_locName = _location->getName();

	_inventory->add(new Item("map", "map of the world!"));
}

Player::~Player()
{
	delete _location;
	delete _inventory;


	_location = nullptr;
	_inventory = nullptr;
}

int Player::getHealth()
{
	return _health;
}

void Player::takeDamage(int damage)
{
	_health -= damage;
}

Inventory* Player::getInventory()
{
	return _inventory;
}

bool Player::checkDirection(const string& dir)
{
	return _location->findConnection(dir) == "";
}

Location* Player::getLocation()
{
	return _location;
}

string Player::getLocName()
{
	return _locName;
}

void Player::setLocName(const string& locName)
{
	_locName = locName;
}

void Player::setLocation(Location* loc)
{
	_location = loc;
}

Entity* Player::findEntityByName(const string& entityName) {
	// Checks if the entity is in the current location
	Entity* entity = _location->findEntityByName(entityName);
	if (entity) return entity;

	// If not, and if the location has sublocations, checks those too
	for (auto& sublocation : _location->getSublocations()) {
		entity = sublocation->findEntityByName(entityName);
		if (entity) return entity;
	}

	return nullptr;  // If entity was not found in location or sublocations
}

