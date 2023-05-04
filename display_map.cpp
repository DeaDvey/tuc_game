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

std::string display_map(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
        //defining map positions
    std::string map[100][114];
    map_defenitions(map);// see map_defenitions.cpp for defining map blocks

    std::string map_describe[100][114];
    map_descriptions(map_describe);

    //variables
    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }

    //locations for easier use
    int location_y = std::stoi(data[key["location_y"]].second);
    int location_x = std::stoi(data[key["location_x"]].second);

    //key for chunk defenitions
    std::string wall_key =       "|||";
    std::string empty_key =      "   ";
    std::string player_key =     " ☺ ";
    std::string water_key =      "≈≈≈";
    std::string teleport_key =   "\\n/";

    int fov = 14; // define field of view, or how far the player can see
    
    std::cout << "╔";
    for (int i = 0; i <= fov * 2; i++) { //print top edge around map
      std::cout << "==="; 
    }
    std::cout << "╗";

        //chat gpt wrote this lmao, it loops over each chunk in the surrounding zone based on fov and prints an ascii image based on what's there
    for (int j = -fov; j <= fov; j++) {
      if (j != -fov) {
	std::cout << "║";
      }
        for (int i = -fov; i <= fov; i++) {
            if (i == 0 && j == 0) { // player spot
                std::cout << player_key;
            } else {
                std::string cell = map[location_x + i][location_y + j];
                if (cell != "") {
                    std::cout << cell;
                }
                else if (cell == "") {
                    std::cout << empty_key;
                }
            }
        }
	std::cout << "║";
        std::cout << "\n"; // move to next row
    }

    std::cout << "╚";
    for (int i = 0; i <= fov * 2; i++) { //print top edge around map
      std::cout << "==="; 
    }
    std::cout << "╝";


    return "done";
}
