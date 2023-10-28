#include "OpenCommand.h"

void OpenCommand::execute(vector<string> args, Player* player)
{
    if (args.size() > 1)
    {
        Entity* entity = player->findEntityByName(args[1]);
        if (entity)
        {
            cout << entity->performAction("open");
        }
        else
        {
            cout << "Cannot find the entity to open.";
        }
    }
    else
    {
        cout << "Specify what you want to open.";
    }
}

