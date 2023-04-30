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

    //std::cout << "-See commands.html for commands-" << "\n\n"; //commented out as it is diaplayed when typing "help"
    while (continue_loop == "true") {//infinite loop until exit is typed
        std::cout << ">> ";
        std::cin >> input;
        //if input is exit, save and end the program
        if (lower(input) == "exit") {
            saveToFile(saveFileName, data); //save data
            std::cout << "\nExiting\n";
            return 0;
        }
        //else, read the input
        else {
            readInput(input, data);
        }
    }
    return "done";
}
