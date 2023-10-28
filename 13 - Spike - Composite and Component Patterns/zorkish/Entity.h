#pragma once
#include <string>
#include <map>
#include "json.hpp"
#include <vector>

using json = nlohmann::json;
using namespace std;

class Entity {
public:
    Entity(json data);
    ~Entity();
    string getName() const;
    string getDescription() const;
    string performAction(const string& actionName);
    string getState() const;
private:
    string _name;
    string _description;
    map<string, string> _attributes;
    map<string, string> _actions;
};

