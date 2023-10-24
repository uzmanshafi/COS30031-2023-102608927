#include "Help.h"

Help::Help(GameManager* manager)
{
	_manager = manager;
}

Help::~Help()
{
}



void Help::update()
{
	processInput();

	switch (_command)
	{
	case '1':
		_manager->pop_state();
		break;
	case '\n':
		_manager->pop_state();
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void Help::render()
{
	std::cout << "Zorkish :: Help\n";
	std::cout << "------------------------\n";
	std::cout << "The following commands are supported:\n";
	std::cout << "quit\n";
	std::cout << "hiscore\n";
	std::cout << "Press Twice Enter to go back.\n";

}
