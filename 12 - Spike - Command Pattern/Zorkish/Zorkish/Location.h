#pragma once
#include <string>
#include <vector>

class Location {
private:
    std::string name;
    std::string description;
    std::vector<std::string> entities;

public:
    Location(const std::string& name, const std::string& description);
    void addEntity(const std::string& entity);
    const std::string& getName() const;
    const std::string& getDescription() const;
    const std::vector<std::string>& getEntities() const;
};
