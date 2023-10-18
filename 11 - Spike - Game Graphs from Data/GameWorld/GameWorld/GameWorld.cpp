    #include <iostream>
    #include <fstream>
    #include <unordered_map>
    #include "json.hpp"
    #include "Location.h"

    using json = nlohmann::json;

    std::unordered_map<std::string, Location*> world;

    void loadGameWorld(const std::string& filename);
    void playGame();

    int main() {
        loadGameWorld("world.json");
        playGame();

        for (const auto& pair : world) {
            delete pair.second;
        }

        return 0;
    }

    void loadGameWorld(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            exit(EXIT_FAILURE);
        }

        json gameData;
        file >> gameData;

        for (const auto& [name, locationData] : gameData.items()) {
            std::string description = locationData["description"];

            Location* loc = new Location(name, description);
            world[name] = loc;
        }

        for (const auto& [name, locationData] : gameData.items()) {
            auto& connections = locationData["connections"];

            for (const auto& [direction, locName] : connections.items()) {
                world[name]->connections[direction] = world[locName];
            }
        }
    }


    void playGame() {
        Location* currentLocation = world.begin()->second;

        while (true) {
            std::cout << "You are at: " << currentLocation->name << std::endl;
            std::cout << currentLocation->description << std::endl;
            std::cout << "Available directions: ";
            for (const auto& [direction, _] : currentLocation->connections) {
                std::cout << direction << " ";
            }
            std::cout << "\nChoose a direction (or type 'quit' to exit): ";
            std::string choice;
            std::getline(std::cin, choice); 

            if (choice == "quit") {
                std::cout << "Goodbye!\n";
                break;
            }

            if (currentLocation->connections.find(choice) != currentLocation->connections.end()) {
                currentLocation = currentLocation->connections[choice];
            }
            else {
                std::cout << "Invalid direction!\n";
                if (std::cin.fail()) { 
                    std::cin.clear();  
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                }
            }
        }
    }
