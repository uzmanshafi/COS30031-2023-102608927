#include "HallOfFame.h"

HallOfFame::HallOfFame(GameManager* manager)
{
	_manager = manager;
}

HallOfFame::~HallOfFame()
{
}

void HallOfFame::update()
{
	processInput(); // Calls the processInput from the base class

	switch (_command)
	{
	case '\n':  // Handles the Enter key
		_manager->pop_state();
		break;
	default:
		cout << "Invalid input." << endl;
	}
}


void HallOfFame::render()
{
	std::cout << "Zorkish :: Hall of Fame\n";
	std::cout << "------------------------\n";
	std::cout << "Top 10 Zorkish Adventure Champions\n";
	std::cout << "	1. Fred, Mountain World, 5000\n";
	std::cout << "	2. Mary, Mountain World, 4000\n";
	std::cout << "	3. Joe, Water World, 3000\n";
	std::cout << "	4. Henry, Mountain World, 2000\n";
	std::cout << "	5. Susan, Mountain World, 1000\n";
	std::cout << "	6. Alfred, Water World, 900\n";
	std::cout << "	7. Clark, Mountain World, 800\n";
	std::cout << "	8. Harold, Mountain World, 500\n";
	std::cout << "	9. Julie, Water World, 300\n";
	std::cout << "	10. Bill, Box World, -5\n";
	std::cout << "Press Enter Twice to return to the Main Menu\n";
}
