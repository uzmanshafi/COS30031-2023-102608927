#pragma once
#include "Message.h"
#include <functional>
#include <map>

class MessageDispatcher {
private:
    std::map<std::string, std::function<void(const Message&)>> listeners;

public:
    void registerListener(const std::string& entityId, std::function<void(const Message&)> listener) {
        listeners[entityId] = listener;
    }

    void sendMessage(const Message& message) {
        if (listeners.count(message.to) > 0) {
            listeners[message.to](message);
        }
    }
};
