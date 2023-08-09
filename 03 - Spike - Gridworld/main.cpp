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

void displayGrid(const char grid[Grid_Size][Grid_Size], const PlayerPostion& playerPosition) {
    for (int x = 0; x < Grid_Size; ++x) {
        for (int y = 0; y < Grid_Size; ++y) {
            if (x == playerPosition.x && y == playerPosition.y) {
                cout << 'P'; // Display the player's position
            } else {
                cout << grid[x][y];
            }
        }
        cout << endl;
    }
}

void displayWelcomeMessage()
{
    cout << "Welcome to the Gridworld: Quantised Excitement. Fate is waiting for You!" << endl;
    cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl;
}


int main()
{
    displayWelcomeMessage();

    bool isGameOver = false;
    bool isPlayerWon = false;
    char user_cmd;
    //create grid
    char grid[Grid_Size][Grid_Size] = {
        {'#', 'G', ' ', 'D', '#', 'D', ' ', ' '},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', '#', '#', ' ', ' ', ' ', 'D', ' '},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', ' ', '#', '#', '#', '#', ' ', ' '},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', '#', 'S', '#', '#', '#', '#', '#'}
    };

    PlayerPostion playerPosition = {8, 2};
}