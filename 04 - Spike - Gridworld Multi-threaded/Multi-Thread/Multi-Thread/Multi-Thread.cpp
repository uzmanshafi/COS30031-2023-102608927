#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <limits>
#include <condition_variable>

using namespace std;

const char Grid_Size = 8;

const char EMPTY = ' ';
const char WALL = '#';
const char START = 'S';
const char GOLD = 'G';
const char DEATH = 'D';

atomic<bool> inputReceived(false);
atomic<bool> isGameOver(false);
atomic<bool> isPlayerWon(false);
atomic<char> user_cmd(' ');
atomic<bool> clearingScreen(false);

mutex mtx;
condition_variable cv;

// structure to be used to hold players position
struct PlayerPosition
{
    char x;
    char y;
} playerPosition{7, 2}; // Initialized to start position

// Function to display the grid
void displayGrid(const char grid[Grid_Size][Grid_Size], const PlayerPosition &playerPosition)
{
    lock_guard<mutex> lock(mtx);
    clearingScreen = true;
    system("cls"); // Clears the screen.
    for (int x = 0; x < Grid_Size; ++x)
    {
        for (int y = 0; y < Grid_Size; ++y)
        {
            if (x == playerPosition.x && y == playerPosition.y)
            {
                cout << 'P';
            }
            else
            {
                cout << grid[x][y];
            }
        }
        cout << endl;
    }
    clearingScreen = false;
}

// Welcome message
void displayWelcomeMessage()
{
    cout << "Welcome to GridWorld! Find the gold and avoid traps!" << endl;
    cout << "Controls: N (north), S (south), E (east), W (west), Q (quit)" << endl;
}

// Function to handles user input
void inputThreadFunction()
{
    char input;
    while (!isGameOver)
    {
        while (clearingScreen)
            this_thread::sleep_for(chrono::milliseconds(1));
 
        {
            // Lock to synchronize access to the console
            lock_guard<mutex> lock(mtx);
            cout << "Enter Your Command: ";
        }

        cin >> input;
        if (!cin)
        {
            // Handles input error
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            {
                lock_guard<mutex> lock(mtx);
                cout << "Invalid command. Please use N, S, E, W, or Q." << endl;
            }
            continue;
        }

        input = toupper(input);
        // Handles valid commands and notify the game loop
        if (input == 'N' || input == 'S' || input == 'E' || input == 'W' || input == 'Q')
        {
            user_cmd = input;
            inputReceived = true;
            cv.notify_one();
        }
        else
        {
            // Handles invalid command
            lock_guard<mutex> lock(mtx);
            cout << "Invalid command. Please use N, S, E, W, or Q." << endl;
        }
    }
}

// Function to handles the game logic
void gameLoopThreadFunction(char grid[Grid_Size][Grid_Size])
{
    while (!isGameOver)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return inputReceived || isGameOver; }); // Waits for input or game over

        if (inputReceived)
        {
            // Process the input
            switch (user_cmd)
            {
            case 'N':
                if (playerPosition.x > 0 && grid[playerPosition.x - 1][playerPosition.y] != WALL)
                {
                    playerPosition.x--;
                    cout << "You have chosen to go North" << endl;
                }
                else
                {
                    cout << "You cannot go that way!" << endl;
                }
                break;
            case 'S':
                if (playerPosition.x < Grid_Size - 1 && grid[playerPosition.x + 1][playerPosition.y] != WALL)
                {
                    playerPosition.x++;
                    cout << "You have chosen to go South" << endl;
                }
                else
                {
                    cout << "You cannot go that way!" << endl;
                }
                break;
            case 'E':
                if (playerPosition.y < Grid_Size - 1 && grid[playerPosition.x][playerPosition.y + 1] != WALL)
                {
                    playerPosition.y++;
                    cout << "You have chosen to go East" << endl;
                }
                else
                {
                    cout << "You cannot go that way!" << endl;
                }
                break;
            case 'W':
                if (playerPosition.y > 0 && grid[playerPosition.x][playerPosition.y - 1] != WALL)
                {
                    playerPosition.y--;
                    cout << "You have chosen to go West" << endl;
                }
                else
                {
                    cout << "You cannot go that way!" << endl;
                }
                break;
            case 'Q':
                cout << "You have chosen to quit the game" << endl;
                isGameOver = true;
                break;
            default:
                break;
            }

            // Checks game state
            if (grid[playerPosition.x][playerPosition.y] == GOLD)
            {
                cout << "Wow - you have discovered a large chest filled with GOLD coins!" << endl;
                cout << "YOU WIN!" << endl;
                isPlayerWon = true;
                isGameOver = true;
            }
            else if (grid[playerPosition.x][playerPosition.y] == DEATH)
            {
                cout << "Arrrrgh... you’ve fallen down a pit." << endl;
                cout << "YOU HAVE DIED!" << endl;
                isPlayerWon = false;
                isGameOver = true;
            }

            inputReceived = false;             // Resets the input flag for the next iteration
            lock.unlock();                     // Unlocks before prompting for the next input
            displayGrid(grid, playerPosition); // Updates the display after each move
        }
    }
}

int main()
{
    displayWelcomeMessage();

    // Initialize grid
    char grid[Grid_Size][Grid_Size] = {
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'G', ' ', 'D', '#', 'D', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', 'S', '#', '#', '#', '#', '#'}};

    displayGrid(grid, playerPosition);

    // Starts threads
    thread inputThread(inputThreadFunction);
    thread gameThread(gameLoopThreadFunction, grid);

    // Waits for threads to finish
    inputThread.join();
    gameThread.join();

    // Game over messages displays
    if (isPlayerWon)
    {
        cout << "Thanks for playing. You Won!." << endl;
    }
    else
    {
        cout << "Thanks for playing. There probably wont be a next time." << endl;
    }

    return 0;
}
