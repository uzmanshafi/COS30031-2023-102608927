#include "SelectAdventure.h"

SelectAdventure::SelectAdventure(GameManager* manager)
{
	_manager = manager;
}

SelectAdventure::~SelectAdventure()
{
}

void SelectAdventure::update()
{
	processInput();

	switch (_command)
	{
	case '1':
	case '2':
	case '3':
		_manager->pop_state();
		_manager->push_state(new Gameplay(_manager));
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void SelectAdventure::render()
{
	std::cout << "Zorkish :: Select Adventure\n";
	std::cout << "------------------------\n";
	std::cout << "Choose your Adventure\n";
	std::cout << "1. Mountain World\n";
	std::cout << "2. Water World\n";
	std::cout << "3. Box World\n";
	std::cout << "Select 1 - 3 :> ";
}
