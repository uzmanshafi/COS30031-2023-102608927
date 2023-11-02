#include "MessageDispatcher.h"

void MessageDispatcher::registerListener(const std::string& entityId, std::function<void(const Message&)> listener) {
    listeners[entityId] = listener;
}

void MessageDispatcher::sendMessage(const Message& message) {
    if (listeners.count(message.to) > 0) {
        listeners[message.to](message);
    }
}
