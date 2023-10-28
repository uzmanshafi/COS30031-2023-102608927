#include "Item.h"
#include <algorithm>
#include <iostream>

Item::Item(const string& name, const string& desc) : _name(name), _desc(desc) {}

Item::~Item() {}

string Item::getName() const {
    return _name;
}

string Item::getDesc() const {
    return _desc;
}

bool Item::hasAttribute(const string& attributeName) {
    return attributes.find(attributeName) != attributes.end();
}

bool Item::getAttributeState(const string& attributeName) {
    if (hasAttribute(attributeName)) {
        return attributes[attributeName];
    }

    cerr << "Error: The attribute '" << attributeName << "' does not exist for item " << _name << "." << endl;
    return false;
}

void Item::setAttributeState(const string& attributeName, bool state) {
    if (hasAttribute(attributeName)) {
        attributes[attributeName] = state;
    }
    else {

        cerr << "Error: The attribute '" << attributeName << "' does not exist for item " << _name << "." << endl;
    }
}

bool Item::canPerformAction(const string& actionName) {
    return find(actions.begin(), actions.end(), actionName) != actions.end();
}
