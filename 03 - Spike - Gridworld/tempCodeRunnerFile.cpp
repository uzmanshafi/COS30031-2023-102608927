switch (user_cmd)
        {
        case 'N':
            if (playerPosition.x > 0 && grid[playerPosition.x - 1][playerPosition.y] != WALL)
            {
                --playerPosition.x;
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
                ++playerPosition.x;
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
                ++playerPosition.y;
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
                --playerPosition.y;
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
        }