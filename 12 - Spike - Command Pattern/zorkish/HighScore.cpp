#include "Highscore.h"

void Highscore::processInput()
{
	cin >> _command;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Highscore::Highscore(GameManager* manager)
{
	_manager = manager;
}

Highscore::~Highscore()
{
}

void Highscore::update()
{
	processInput();

	_manager->pop_state();
	_manager->push_state(new HallOfFame(_manager));
}

void Highscore::render()
{
	std::cout << "Zorkish :: New Highscore\n";
	std::cout << "------------------------\n";
	std::cout << "Congratulations!\n";
	std::cout << "You have made it to the Zorkish Hall Of Fame\n";
	std::cout << "Adventure:\n";
	std::cout << "Score:\n";
	std::cout << "Moves:\n";
	std::cout << "Please type your name and press enter:\n";
	std::cout << ":> ";
}
