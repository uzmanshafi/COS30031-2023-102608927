#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main() {
    // Opens the file
    std::ifstream file("test3.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }

    // Parses the file using nlohmann::json library
    nlohmann::json jsonObj;
    file >> jsonObj;

    // Prints the content to the screen
    for (auto& [key, value] : jsonObj.items()) {
        std::cout << key << " : " << value.dump() << std::endl;
    }


    return 0;
}
