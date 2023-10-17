#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::ifstream file("test2.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }

    std::string line;
    while (getline(file, line)) {
        // Removes whitespace from the start and end of the string
        line.erase(0, line.find_first_not_of(' '));
        line.erase(line.find_last_not_of(' ') + 1);

        // Ignores blank lines and lines starting with #
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Splits the line and print each part
        std::vector<std::string> parts = split(line, ':');
        for (const std::string& part : parts) {
            std::cout << part << " ";
        }
        std::cout << std::endl;
    }

    file.close();
    return 0;
}
