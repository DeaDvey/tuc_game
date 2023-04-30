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

std::string tutorial(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
    std::string tutorial_finished = "false";
    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }

    //tutorial start
    //color codes
    std::string fatal_error_color = "\033[31m";
    std::string error_color = "\033[33m";
    std::string dialouge_color = "\033[3;32m";
    std::string command_info_color = "\033[34m";
    std::string general_color = "\033[0m";





    //Underlander tutorial
    if (data[key["species"]].second == "Underlander") {
        //set location
        data[key["location_x"]].second = "27";
        data[key["location_y"]].second = "33";

        //output text
        std::cout << dialouge_color << "'Wake up " << data[key["name"]].second << ", The Gnawers are attacking, we must escape on the Fliers'" << general_color << "\n";
        data[key["physical_position"]].second = "lying";
    }

    //Overlander tutorial
    if (data[key["species"]].second == "Overlander") {
        //set location
        data[key["location_x"]].second = "41";
        data[key["location_y"]].second = "28";

        //output text
        std::cout << dialouge_color << "'Who are you, who are'";
        std::cout << general_color << "you hear a high pitched voice say suddenly. What had happened you ask yourself, the last thin you remember was falling... forever, then everything went black" << "\n";
        std::cout << command_info_color << "Type 'stand' to stand up" << general_color << "\n";
        data[key["physical_position"]].second = "sitting";

    }

    //Gnawer tutorial
    if (data[key["species"]].second == "Gnawer") {
        //set location
        data[key["location_x"]].second = "26";
        data[key["location_y"]].second = "34";
        //output text
        std::cout << dialouge_color << "'Quick, get up " << data[key["name"]].second << " The Bane is saying we attack the human outpost in 15 minutes, get up!'" << general_color << "\n";
        data[key["physical_position"]].second = "lying";
    }





    //check if tutorial is finished
    if (tutorial_finished == "true") {
        std::cout << "finished tutorial!" << "\n";
        data[key["state"]].second = "main";//change state to main state
    }
    saveToFile(saveFileName, data); //save data
    return "done";
}
