#pragma once
#include <string>

struct Message {
    std::string from;
    std::string to;
    std::string kind;
    std::string data; // I just used a simple string for demoing

    Message(const std::string& from, const std::string& to, const std::string& kind, const std::string& data)
        : from(from), to(to), kind(kind), data(data) {}
};
