#include <iostream>
#include <iostream>
#include <fstream> // for file input/output
#include <string> // for string operations
#include <algorithm>
#include <cstring>
#include <map>//map variables
#include <cstdlib>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <cctype>
#include "header.h"
#include <chrono>
#include <thread>

void run_loop() {
    while (true) {
        // Call your function
        recieve_chat();

        // Sleep for 5 seconds
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

void saveToFile(const std::string& fileName, const std::vector<std::pair<std::string, std::string>>& data) {
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (const auto& [key, val] : data) {
            outFile << val << std::endl;
        }
        outFile.close();
    }
    else {
        std::cout << "Error: could not save to file" << std::endl;
    }
}

//                        ===load variables in data from save file===
void loadFromFile(const std::string& fileName, std::vector<std::pair<std::string, std::string>>& data) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        int i = 0;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string value;
            if (std::getline(iss, value)) {
                data[i].second = value;
                i++;
            }
        }
        inFile.close();
    }
    else {
        std::cout << "Error: could not load from file" << std::endl;
    }
}

//          convert strings to lower or uppercase
//toupper function
std::string upper(std::string& text) {
    //std::string uppertext;
    for (auto& c : text) {
        c = toupper(c);
    }

    return text;
}
//tolower function
std::string lower(std::string& text) {
    //std::string uppertext;
    for (auto& c : text) {
        c = tolower(c);
    }

    return text;
}




