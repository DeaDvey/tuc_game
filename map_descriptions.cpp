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

std::string map_descriptions(std::string map_describe[100][84]) {
    //regalia
    map_describe[31][1] = "wall";
    map_describe[32][1] = "wall";
    map_describe[33][1] = "wall";
    map_describe[34][1] = "wall";
    map_describe[34][1] = "wall";
    map_describe[35][1] = "wall";
    map_describe[36][2] = "wall";
    map_describe[37][2] = "wall";
    map_describe[38][2] = "wall";
    map_describe[39][2] = "wall";
    map_describe[40][3] = "wall";
    map_describe[41][4] = "wall";
    map_describe[41][5] = "wall";
    map_describe[42][6] = "wall";
    map_describe[41][7] = "wall";
    map_describe[41][8] = "wall";
    map_describe[41][9] = "wall";
    map_describe[41][10] = "wall";
    map_describe[40][11] = "wall";
    map_describe[39][12] = "wall";
    map_describe[38][13] = "wall";
    map_describe[37][13] = "wall";
    map_describe[36][13] = "wall";
    map_describe[35][13] = "wall";
    map_describe[34][13] = "wall";
    //[33][13] is a teleport block
    map_describe[32][13] = "wall";
    map_describe[31][13] = "wall";
    map_describe[30][12] = "wall";
    map_describe[29][12] = "wall";
    map_describe[28][11] = "wall";
    map_describe[27][10] = "wall";
    map_describe[26][10] = "wall";
    map_describe[25][9] = "wall";
    map_describe[25][8] = "wall";
    map_describe[25][7] = "wall";
    map_describe[25][6] = "wall";
    map_describe[25][5] = "wall";
    map_describe[26][4] = "wall";
    map_describe[27][3] = "wall";
    map_describe[28][2] = "wall";
    map_describe[29][2] = "wall";
    map_describe[30][2] = "wall";

    //water in waterway
    map_describe[45][31] = "water";
    map_describe[46][31] = "water";
    map_describe[47][31] = "water";

    //teleports
    map_describe[33][13] = "46 29";
    map_describe[46][28] = "33 12";
    return "done";
}
