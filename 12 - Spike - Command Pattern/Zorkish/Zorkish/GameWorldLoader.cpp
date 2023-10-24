#include "GameWorldLoader.h"
#include <fstream>
#include "Location.h"
#include "json.hpp" 

using json = nlohmann::json;

json GameWorldLoader::LoadAdventure(const std::string& filepath) {
    std::ifstream file(filepath);
    json j;
    file >> j;
    return j;
}

std::vector<Location> GameWorldLoader::LoadLocations(const std::string& filepath) {
    json j = LoadAdventure(filepath);
    std::vector<Location> locations;

    for (auto& locationData : j["locations"]) {
        Location location(locationData["name"], locationData["description"]);
        for (auto& entity : locationData["entities"]) {
            location.addEntity(entity);
        }
        locations.push_back(location);
    }

    return locations;
}
