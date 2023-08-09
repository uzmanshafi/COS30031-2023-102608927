#include <iostream>


using namespace std;

const char Grid_Size = 8;

const char EMPTY = ' ';
const char WALL = '#';
const char START = 'S';
const char GOLD = 'G';
const char DEATH = 'D';

//structure to be used to hold plauers position
struct PlayerPostion
{
    char x;
    char y;
};

void displayWelcomeMessage()
{
    cout << "Welcome to the Gridworld: Quantised Excitement. Fate is waiting for You!" << endl;
    cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl;
}


int main()
{
    displayWelcomeMessage();
}