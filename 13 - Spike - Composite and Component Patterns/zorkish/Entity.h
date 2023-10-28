#pragma once
#include <map>
#include <string>
#include "Component.h"

class Entity {
private:
    std::map<std::string, Component*> _components;
public:
    void addComponent(const std::string& componentName, Component* component);
    Component* getComponent(const std::string& componentName);
    void update();
};
