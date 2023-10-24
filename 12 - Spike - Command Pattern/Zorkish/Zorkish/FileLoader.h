#include <string>
#include <vector>
#include "json.hpp"

class Entity {
public:
    std::string name;
    std::string description;
};

class Location {
public:
    std::string name;
    std::string description;
    std::vector<Entity> entities;
};

class FileLoader {
public:
    static std::vector<Location> load(const std::string& filePath);
};
