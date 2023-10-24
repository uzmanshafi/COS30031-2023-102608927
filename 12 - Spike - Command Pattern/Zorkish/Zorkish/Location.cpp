#include "Location.h"

Location::Location(const std::string& name, const std::string& description)
    : name(name), description(description) {}

void Location::addEntity(const std::string& entity) {
    entities.push_back(entity);
}

const std::string& Location::getName() const {
    return name;
}

const std::string& Location::getDescription() const {
    return description;
}

const std::vector<std::string>& Location::getEntities() const {
    return entities;
}
