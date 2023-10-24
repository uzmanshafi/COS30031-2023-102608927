#include "About.h"

About::About(GameManager* manager)
{
	_manager = manager;
}

About::~About()
{
}

void About::update()
{
	processInput();

	switch (_command)
	{
	case '1':
		_manager->pop_state();
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void About::render()
{
	std::cout << "Zorkish :: About\n";
	std::cout << "------------------------\n";
	std::cout << "Written by : Mohamed Shafi Uzman Fassy\n";
	std::cout << "Press Enter to Return to the Main Menu\n";
}
