#include "Exit.h"

Exit::Exit(GameManager* manager)
{
	_manager = manager;
}

Exit::~Exit()
{
}

void Exit::update()
{
	processInput();

	switch (_command)
	{
	case '1':
		_manager->pop_state();
		_manager->pop_state();
		break;
	case '2':
		_manager->pop_state();
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void Exit::render()
{
	std::cout << "Zorkish :: Exit?\n";
	std::cout << "------------------------\n";
	std::cout << "1. Quit\n";
	std::cout << "2. Back\n";
	std::cout << "Select 1 - 2 :> ";
}
