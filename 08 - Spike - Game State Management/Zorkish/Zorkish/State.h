#pragma once

class State {
public:
    virtual void initialize() = 0; // Setting the stage
    virtual void run() = 0;        // Running the scene
    virtual void terminate() = 0;  // Cleaning up the stage
    virtual void handleInput() = 0;
};
