#pragma once
#include <unordered_map>
#include <string>

class Location {
public:
    std::string name;
    std::string description;
    std::unordered_map<std::string, Location*> connections;

    Location(const std::string& name, const std::string& description);
};