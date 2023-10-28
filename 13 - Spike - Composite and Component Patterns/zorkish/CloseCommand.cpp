#include "CloseCommand.h"

void CloseCommand::execute(vector<string> args, Player* player)
{
    if (args.size() < 2)
    {
        cout << "Close what?" << endl;
        return;
    }

    string entityName = args[1];
    Location* currentLocation = player->getLocation();

    Entity* entity = currentLocation->findEntityByName(entityName);

    if (entity)
    {
        string result = entity->performAction("close");
        cout << result << endl;
    }
    else
    {
        cout << "Cannot find " << entityName << " to close." << endl;
    }
}