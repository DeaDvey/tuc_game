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


//                        ===read user input and determine the output===
std::string readInput(std::string& input, std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
    //variables
    std::cout << "\n"; //seperate up input and output

    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }

    std::string output;//set what should be outputted
    input = lower(input);

    //change phyisical position (sitting/standing/laying)
    //standing
    if (input == "stand" || input == "standing") {
        data[key["physical_position"]].second = "standing";
        std::cout << "You are now standing" << "\n";
    }
    //sitting
    else if (input == "sit" || input == "sitting") {
        data[key["physical_position"]].second = "sitting";
        std::cout << "You are now sitting" << "\n";
    }
    //laying
    else if (input == "lay" || input == "lie" || input == "laying" || input == "lying") {
        data[key["physical_position"]].second = "lying";
        std::cout << "You are now lying down" << "\n";
    }

    //print info/specific info
    else if (input == "info" || input == "information") {
        std::cout << "Species: " << data[key["species"]].second << "\n";
        std::cout << "Pronouns: " << data[key["first_pronoun"]].second << "/";
        std::cout << data[key["second_pronoun"]].second << "\n";
        std::cout << "Name: " << data[key["name"]].second << "\n";
        std::cout << "State: " << data[key["state"]].second << "\n";
        std::cout << "Location: " << data[key["location_x"]].second << ", " << data[key["location_y"]].second << "\n";
    }

    //help the user
    else if (input == "help") {
        std::cout << "See resources/tucgame.html for commands" << "\n";
        std::cout << "It looks best in a web browser display" << "\n";
    }

    //traveling
    else if (input == "n" || input == "north") {
        travel("n", data, saveFileName);
    }



    //else tell user they must of typoed
    else {
        std::cout << "Sorry, this command does not exist, please check your spelling and check it is a valid command" << "\n";
    }

    std::cout << "\n"; //seperate up input and output

    return output;
}
