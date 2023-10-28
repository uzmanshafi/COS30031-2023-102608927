#pragma once

class Entity;

class Component {
public:
    virtual ~Component() {}
    virtual void update(Entity* entity) = 0;  // Update behavior, if needed
};
