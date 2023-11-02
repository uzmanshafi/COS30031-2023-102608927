#include "Entity.h"

Entity::Entity(const std::string& id, MessageDispatcher* dispatcher)
    : id(id), dispatcher(dispatcher) {}

Entity::~Entity() = default;

void Entity::sendMessage(const Message& message) {
    dispatcher->sendMessage(message);
}

std::string Entity::getId() const {
    return id;
}
