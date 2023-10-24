#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "json.hpp"

using json = nlohmann::json;

class GameWorldLoader 
{
public:
    static json LoadAdventure(const std::string& filepath);
};

