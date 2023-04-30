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

std::string game(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
    //variables
    std::string input;
    std::string continue_loop = "true";
    std::string tutorial_finished = "false";
    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }
    std::cout << "\n";

    //std::cout << "-See commands.html for commands-" << "\n\n"; //commented out as it is diaplayed when typing "help"
    while (continue_loop == "true") {//infinite loop until exit is typed
        std::cout << ">> ";
        std::cin >> input;
        //if input is exit, save and end the program
        if (lower(input) == "exit") {
            continue_loop = "false";
            saveToFile(saveFileName, data); //save data
            std::cout << "\nExiting\n";
            return "done";
        }
        //else, read the input
        else {
            readInput(input, data, saveFileName);
        }
    }
    return "done";
}
