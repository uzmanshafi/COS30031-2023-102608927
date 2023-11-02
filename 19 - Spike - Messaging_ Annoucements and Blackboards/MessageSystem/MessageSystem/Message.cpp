#include "Message.h"

Message::Message(const std::string& from, const std::string& to, const std::string& kind, const std::string& data)
    : from(from), to(to), kind(kind), data(data) {}
