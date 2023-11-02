#pragma once
#include "MessageDispatcher.h"
#include <string>

class Entity {
protected:
    std::string id;
    MessageDispatcher* dispatcher;

public:
    Entity(const std::string& id, MessageDispatcher* dispatcher);
    virtual ~Entity();
    virtual void receiveMessage(const Message& message) = 0;
    void sendMessage(const Message& message);
    std::string getId() const;
};
