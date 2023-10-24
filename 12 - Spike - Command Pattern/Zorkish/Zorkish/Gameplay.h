#pragma once
#include "State.h"
#include "Location.h"
#include <vector>

class Gameplay : public State {
public:
    void initialize() override;
    void run() override;
    void terminate() override;
    void handleInput() override;
    Gameplay();
    Gameplay(const std::vector<Location>& locs);
    void moveToNextLocation();
    std::string getCurrentLocationName();
    std::string getCurrentLocationDescription();
private:
    std::vector<Location> locations;
    int currentLocationIndex;
};
