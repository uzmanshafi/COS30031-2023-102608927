#include "GoCommand.h"

void GoCommand::execute(vector<string> command, Player* player)
{
    Location* pLoc = player->getLocation();

    if (command.size() == 2)
    {
        const string pCon = pLoc->findConnection(command.at(1));

        if (pCon == "")
        {
            cout << "Invalid direction. Please choose another direction." << endl;
        }
        else
        {
            player->setLocName(pCon);
        }
    }
    else if (command.size() > 2 && command[1] == "into")
    {
        // Handles moving into a sublocation
        Location* subLoc = pLoc->findSublocation(command.at(2));
        if (subLoc)
        {
            player->setLocation(subLoc);
        }
        else
        {
            cout << "Invalid sublocation. Please choose another sublocation." << endl;
        }
    }
    else
    {
        cout << "Unable to process command. Please input a valid command and direction." << endl;
    }
}
