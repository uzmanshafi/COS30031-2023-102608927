#pragma once
#include "Entity.h"

class Chest : public Entity {
public:
    using Entity::Entity;
    void receiveMessage(const Message& message) override;
};
