#include "MainMenu.h"

MainMenu::MainMenu(GameManager* manager)
{
	_manager = manager;
}

MainMenu::~MainMenu()
{
	delete _manager;
	_manager = nullptr;
}

void MainMenu::update()
{
	processInput();

	switch (_command)
	{
	case '1':
		_manager->push_state(new SelectAdventure(_manager));
		break;
	case '2':
		_manager->push_state(new HallOfFame(_manager));
		break;
	case '3':
		_manager->push_state(new Help(_manager));
		break;
	case '4':
		_manager->push_state(new About(_manager));
		break;
	case '5':
		_manager->push_state(new Exit(_manager));
		break;
	default:
		cout << "Invalid input." << endl;
	}
}

void MainMenu::render()
{
	std::cout << "Zorkish :: Main Menu\n";
	std::cout << "------------------------\n";
	std::cout << "1. Select Adventure and Play\n";
	std::cout << "2. Hall of Fame\n";
	std::cout << "3. Help\n";
	std::cout << "4. About\n";
	std::cout << "5. Quit\n";
	std::cout << "Select 1 - 5 :> ";
}
