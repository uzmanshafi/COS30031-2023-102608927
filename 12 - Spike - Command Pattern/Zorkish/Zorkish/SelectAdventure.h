#pragma once
#include "State.h"
#include <string>


class SelectAdventure : public State {
public:
    void initialize() override;
    void run() override;
    void terminate() override;
    void handleInput() override;
private:
    void loadAdventure(const std::string& filename);
};
