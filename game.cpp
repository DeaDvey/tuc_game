//include statements
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

//function that handles the main game state
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
    //color codes
    std::string fatal_error_color = "\033[31m";
    std::string error_color = "\033[33m";
    std::string dialouge_color = "\033[3;32m";
    std::string command_info_color = "\033[34m";
    std::string general_color = "\033[0m";
    //variables ^^


    //checks that the loop should still happen (failsafe)
    while (continue_loop == "true") {//infinite loop until exit is typed
      std::cout << ">> "; // display a >> to show the user that they can type
      getline(std::cin, input); // read the users input, works if spaces present
      
        //if input is exit, save and end the program
        if (lower(input) == "exit") {
            continue_loop = "false";
            saveToFile(saveFileName, data); //save data before exit
            std::cout << "\nExiting\n";
            return "done"; //return done
        }
	
        //else, send the input to a process funtion that handles it
        else {;
	  readInput(input, data, saveFileName); // read user input and determine output
        }
    }
    return "done"; //return done if loop breaks but error occurs so doesn't return above
}
