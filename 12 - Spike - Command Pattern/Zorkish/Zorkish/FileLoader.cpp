#include "FileLoader.h"
#include <fstream>
#include <iostream>

std::vector<Location> FileLoader::load(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        exit(1);
    }

    nlohmann::json jsonData;
    inputFile >> jsonData;

    std::vector<Location> locations;
    for (const auto& loc : jsonData["locations"]) {
        Location location;
        location.name = loc["name"];
        location.description = loc["description"];
        for (const auto& entity : loc["entities"]) {
            Entity e;
            e.name = entity["name"];
            e.description = entity["description"];
            location.entities.push_back(e);
        }
        locations.push_back(location);
    }
    return locations;
}
