#include "Gameplay.h"

void Gameplay::processInput()
{
	cin >> _command;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Gameplay::Gameplay(GameManager* manager)
{
	_manager = manager;
}

Gameplay::~Gameplay()
{
}

void Gameplay::update()
{
	processInput();

	if (_command == "quit")
	{
		_manager->pop_state();
	}
	else if (_command == "hiscore")
	{
		_manager->pop_state();
		_manager->push_state(new Highscore(_manager));
	}
	else
		cout << "Invalid input." << endl;
}

void Gameplay::render()
{
	std::cout << "Welcome to Zorkish :: Void World\n";
	std::cout << "------------------------\n";
	std::cout << "This world is simple and pointless. Used it to test Zorkish phase 1 spec.\n";
	std::cout << ":> ";
}
