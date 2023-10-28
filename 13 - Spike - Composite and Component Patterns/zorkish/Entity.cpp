#include "Entity.h"


Entity::Entity(json data) : _name(data["name"]), _description(data["desc"]) {
    if (data.contains("attributes")) {
        _attributes = data["attributes"].get<map<string, string>>();
    }

    if (data.contains("actions")) {
        _actions = data["actions"].get<map<string, string>>();
    }
}

string Entity::getName() const {
    return _name;
}


string Entity::getDescription() const {
    return _description;
}

string Entity::performAction(const string& actionName) {
    if (_actions.find(actionName) != _actions.end()) {
        if (actionName == "open") {
            _attributes["state"] = "open";
        }
        else if (actionName == "close") {
            _attributes["state"] = "closed";
        }
        return _actions[actionName];
    }
    return "Cannot perform this action on " + _name;
}
