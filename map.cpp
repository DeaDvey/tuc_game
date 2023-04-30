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
#include <array>
#include "header.h"

std::string map(const std::string& direction, std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
    //defining map positions
    std::string map[100][84];
    map[8][13] = "wall";

    //other variables
    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }



    return "done";
}


std::string travel(const std::string& direction, std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
    //defining map positions
    std::string map[100][84];
    map[8][13] = "wall";
    map[33][13] = "46 29";




    //variables
    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }
    int location_y = std::stoi(data[key["location_y"]].second);
    int location_x = std::stoi(data[key["location_x"]].second);


    //north
    if (direction == "n") {
        location_y--;
        //if it's a wall/water/lava/other
        if (map[location_x][location_y] == "wall" || map[location_x][location_y] == "water" || map[location_x][location_y] == "lava") {
            return "cannot go there";
        }

        //if it's a teleport block
        else if (map[location_x][location_y] != "") {
            std::istringstream iss(map[location_x][location_y]);
             if (!(iss >> location_x >> location_y)) {
                std::cerr << "Error: could not extract integers from string" << std::endl;
                return "failed";
             }
             std::cout << "location_x = " << location_x << std::endl;
             std::cout << "location_y = " << location_y << std::endl;

        }


        data[key["location_y"]].second = std::to_string(location_y);
        data[key["location_x"]].second = std::to_string(location_x);

    }

    return "traveled";
}
