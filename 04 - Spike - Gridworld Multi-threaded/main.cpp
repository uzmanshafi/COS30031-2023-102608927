#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <condition_variable>

using namespace std;

const int Grid_Size = 8;

const char EMPTY = ' ';
const char WALL = '#';
const char START = 'S';
const char GOLD = 'G';
const char DEATH = 'D';

// Atomic flags to control the game state.
atomic<bool> isGameOver(false);
atomic<bool> isPlayerWon(false);

// Mutex and condition variable for synchronizing access to input.
mutex mtx;
condition_variable cv;

// structure to be used to hold player's position
struct PlayerPosition
{
    char x;
    char y;
} playerPosition;

char user_cmd;

// function to display the grid.
void displayGrid(const char grid[Grid_Size][Grid_Size], const PlayerPosition &playerPosition)
{
    for (int x = 0; x < Grid_Size; ++x)
    {
        for (int y = 0; y < Grid_Size; ++y)
        {
            if (x == playerPosition.x && y == playerPosition.y)
            {
                cout << 'P'; // Displays the player's position
            }
            else
            {
                cout << grid[x][y];
            }
        }
        cout << endl;
    }
}

// function to display the welcome message.
void displayWelcomeMessage()
{
    cout << "Welcome to the Gridworld: Quantised Excitement. Fate is waiting for You!" << endl;
    cout << "Valid commands: N, S, E, and W for direction. Q to quit the game." << endl;
}

// function to process the player's input.
void processInput() {
    while (!isGameOver) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !isGameOver; });  // Waits until it's safe to get input.

        if (isGameOver) break; // If game is over, breaks the loop.

        cin >> user_cmd; // Gets input.
        user_cmd = toupper(user_cmd);

        lock.unlock();
        cv.notify_one();  // Notifies the game loop that input is available.
    }
}

// function to run the game loop.
void gameLoop(char grid[Grid_Size][Grid_Size], PlayerPosition &playerPosition) {
    while (!isGameOver) {
        // Waits for input
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return user_cmd != '\0' || isGameOver; });

        // Checks if the game is over after waking up
        if (isGameOver) {
            break;
        }

        // Copies the user_cmd to local variable and reset it
        char command = user_cmd;
        user_cmd = '\0';
        lock.unlock(); // Unlocks as soon as possible

        // Handles user input
        switch (command) {
            case 'N':
                if (playerPosition.x > 0 && grid[playerPosition.x - 1][playerPosition.y] != WALL) {
                    --playerPosition.x;
                    cout << "You have chosen to go North" << endl;
                } else {
                    cout << "You cannot go that way!" << endl;
                }
                break;
            case 'S':
                if (playerPosition.x < Grid_Size - 1 && grid[playerPosition.x + 1][playerPosition.y] != WALL) {
                    ++playerPosition.x;
                    cout << "You have chosen to go South" << endl;
                } else {
                    cout << "You cannot go that way!" << endl;
                }
                break;
            case 'E':
                if (playerPosition.y < Grid_Size - 1 && grid[playerPosition.x][playerPosition.y + 1] != WALL) {
                    ++playerPosition.y;
                    cout << "You have chosen to go East" << endl;
                } else {
                    cout << "You cannot go that way!" << endl;
                }
                break;
            case 'W':
                if (playerPosition.y > 0 && grid[playerPosition.x][playerPosition.y - 1] != WALL) {
                    --playerPosition.y;
                    cout << "You have chosen to go West" << endl;
                } else {
                    cout << "You cannot go that way!" << endl;
                }
                break;
            case 'Q':
                isGameOver = true;
                cout << "You have chosen to quit the game." << endl;
                break;
            default:
                cout << "Invalid command!" << endl;
                break;
        }

        // Checks the result of the move
        if (grid[playerPosition.x][playerPosition.y] == GOLD) {
            cout << "Wow - you have discovered a large chest filled with GOLD coins!" << endl;
            cout << "YOU WIN!" << endl;
            isPlayerWon = true;
            isGameOver = true;
        } else if (grid[playerPosition.x][playerPosition.y] == DEATH) {
            cout << "Arrrrgh... you’ve fallen down a pit." << endl;
            cout << "YOU HAVE DIED!" << endl;
            isPlayerWon = false;
            isGameOver = true;
        }

        // Displays the grid and player position
        displayGrid(grid, playerPosition);

        // Notifies the input thread that it can accept another input
        cv.notify_one();
    }
}


int main()
{
    displayWelcomeMessage();

    // creates grid
    char grid[Grid_Size][Grid_Size] = {
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'G', ' ', 'D', '#', 'D', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', 'S', '#', '#', '#', '#', '#'}};

    // Sets the player's initial position
    PlayerPosition playerPosition = {7, 2};

    // Starts the input processing in a separate thread
    thread inputThread(processInput);

    // Starts the game loop in the main thread
    gameLoop(grid, playerPosition);

    // Waits for the input thread to finish before exiting the program
    inputThread.join();

    // Final game state message
    if (isPlayerWon) {
        cout << "Thanks for playing. You've won!" << endl;
    } else {
        cout << "Thanks for playing. There probably wont be a next time." << endl;
    }

    return 0;
}
