#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Location.h" 
#include "json.hpp"

using json = nlohmann::json;

class GameWorldLoader
{
public:
    static json LoadAdventure(const std::string& filepath);
    static std::vector<Location> LoadLocations(const std::string& filepath);
};
