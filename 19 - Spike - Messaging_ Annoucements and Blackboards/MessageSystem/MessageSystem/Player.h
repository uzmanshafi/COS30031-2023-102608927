#pragma once
#include "Entity.h"

class Player : public Entity {
public:
    using Entity::Entity;
    void receiveMessage(const Message& message) override;
};
