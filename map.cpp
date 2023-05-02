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

std::string travel(const std::string& direction, std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
    //defining map positions
    std::string map[100][84];
    map_defenitions(map);// see map_defenitions.cpp for defining map blocks

    //variables
    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }
    int location_y = std::stoi(data[key["location_y"]].second);
    int location_x = std::stoi(data[key["location_x"]].second);


    //direction traveling
    if (direction == "north") {
        location_y--;
    }
    else if (direction == "south") {
        location_y++;
    }
    else if (direction == "east") {
        location_x++;
    }
    else if (direction == "west") {
        location_x--;
    }
    //if it's a wall/water/lava/other
    if (map[location_x][location_y] == "wall" || map[location_x][location_y] == "water" || map[location_x][location_y] == "lava") {
        std::cout << "You hit: " << map[location_x][location_y] << "\n"; //tell user they hit something impassible
        return "cannot go there";
    }

    //if it's a teleport block
    else if (map[location_x][location_y] != "" && map[location_x][location_y].length() <= 7) {
        std::istringstream iss(map[location_x][location_y]);
        if (!(iss >> location_x >> location_y)) {
            std::cerr << "Error: could not extract integers from string" << std::endl;
            return "failed";
        }
        // std::cout << "location_x = " << location_x << std::endl;
        // std::cout << "location_y = " << location_y << std::endl;

    }


    data[key["location_y"]].second = std::to_string(location_y);
    data[key["location_x"]].second = std::to_string(location_x);
    std::cout << "Moved " << direction << " to " << location_x << ", " <<location_y << "\n";
    if (map[location_y][location_x] != "") {
        std::cout << "\n" << map[location_x][location_y] << "\n";
    }


    return "traveled";
}
