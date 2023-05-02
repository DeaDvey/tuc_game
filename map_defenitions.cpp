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

std::string map_defenitions(std::string map[100][84]) {
    //regalia
    map[31][1] = "wall";
    map[32][1] = "wall";
    map[33][1] = "wall";
    map[34][1] = "wall";
    map[34][1] = "wall";
    map[35][1] = "wall";
    map[36][2] = "wall";
    map[37][2] = "wall";
    map[38][2] = "wall";
    map[39][2] = "wall";
    map[40][3] = "wall";
    map[41][4] = "wall";
    map[41][5] = "wall";
    map[42][6] = "wall";
    map[41][7] = "wall";
    map[41][8] = "wall";
    map[41][9] = "wall";
    map[41][10] = "wall";
    map[40][11] = "wall";
    map[39][12] = "wall";
    map[38][13] = "wall";
    map[37][13] = "wall";
    map[36][13] = "wall";
    map[35][13] = "wall";
    map[34][13] = "wall";
    //[33][13] is a teleport block
    map[32][13] = "wall";
    map[31][13] = "wall";
    map[30][12] = "wall";
    map[29][12] = "wall";
    map[28][11] = "wall";
    map[27][10] = "wall";
    map[26][10] = "wall";
    map[25][9] = "wall";
    map[25][8] = "wall";
    map[25][7] = "wall";
    map[25][6] = "wall";
    map[25][5] = "wall";
    map[26][4] = "wall";
    map[27][3] = "wall";
    map[28][2] = "wall";
    map[29][2] = "wall";
    map[30][2] = "wall";

    //water in waterway
    map[45][31] = "water";
    map[46][31] = "water";
    map[47][31] = "water";

    //teleports
    map[33][13] = "46 29";
    map[46][28] = "33 12";
    return "done";
}
