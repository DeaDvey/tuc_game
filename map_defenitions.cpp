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
    std::string wall_key =     "|||";
    std::string water_key =    "≈≈≈";
    std::string teleport_key = " ⌂ ";


    //regalia
    map[31][1] = wall_key;
    map[32][1] = wall_key;
    map[33][1] = wall_key;
    map[34][1] = wall_key;
    map[34][1] = wall_key;
    map[35][1] = wall_key;
    map[36][2] = wall_key;
    map[37][2] = wall_key;
    map[38][2] = wall_key;
    map[39][2] = wall_key;
    map[40][3] = wall_key;
    map[41][4] = wall_key;
    map[41][5] = wall_key;
    map[42][6] = wall_key;
    map[41][7] = wall_key;
    map[41][8] = wall_key;
    map[41][9] = wall_key;
    map[41][10] = wall_key;
    map[40][11] = wall_key;
    map[39][12] = wall_key;
    map[38][13] = wall_key;
    map[37][13] = wall_key;
    map[36][13] = wall_key;
    map[35][13] = wall_key;
    map[34][13] = wall_key;
    //[33][13] is a teleport block
    map[32][13] = wall_key;
    map[31][13] = wall_key;
    map[30][12] = wall_key;
    map[29][12] = wall_key;
    map[28][11] = wall_key;
    map[27][10] = wall_key;
    map[26][10] = wall_key;
    map[25][9] = wall_key;
    map[25][8] = wall_key;
    map[25][7] = wall_key;
    map[25][6] = wall_key;
    map[25][5] = wall_key;
    map[26][4] = wall_key;
    map[27][3] = wall_key;
    map[28][2] = wall_key;
    map[29][2] = wall_key;
    map[30][2] = wall_key;

    //river up to and around the fount
    map[49][30] = water_key;
    map[50][30] = water_key;
    for (int i = 29; i >= 22; i--) {
        map[50][i] = water_key;
    }
    map[51][22] = water_key;
    map[52][21] = water_key;
    map[52][20] = water_key;
    map[52][19] = water_key;
    map[52][18] = water_key;
    map[51][18] = water_key;
    for (int i = 15; i <= 17; i++) {
        map[50][i] = water_key;
    }
    map[49][18] = water_key;
    map[48][19] = water_key;
    map[48][20] = water_key;
    map[49][21] = water_key;

    //river to the west of Regalia
    map[39][31] = water_key;
    map[38][30] = water_key;
    map[37][29] = water_key;
    map[36][28] = water_key;
    map[36][27] = water_key;
    map[35][26] = water_key;
    map[35][26] = water_key;
    map[34][25] = water_key;
    map[33][25] = water_key;
    map[32][25] = water_key;
    map[33][24] = water_key;
    map[32][23] = water_key;

    //mountain west of regalia
    map[36][25] = wall_key;
    map[36][26] = wall_key;
    map[35][27] = wall_key;
    map[34][28] = wall_key;
    map[34][27] = wall_key;
    map[34][26] = wall_key;
    map[35][25] = wall_key;
    map[35][24] = wall_key;
    map[34][24] = wall_key;
    map[34][23] = wall_key;

    //mountain north of regalia
    for (int i = 38; i <= 42; i++) {
        for (int j = 17; j <= 22; j++) {
            map[i][j] = wall_key;
        }
    }
    for (int i = 17; i <= 21; i++) {
        map[43][i] = wall_key;
    }
    map[44][17] = wall_key;
    map[44][18] = wall_key;
    map[44][19] = wall_key;
    map[45][17] = wall_key;
    map[45][18] = wall_key;
    for (int i = 33; i <= 38; i++) {
        for (int j = 16; j <= 19; j++) {
            map[i][j] = wall_key;
        }
    }
    map[35][20] = wall_key;
    map[36][20] = wall_key;
    map[37][20] = wall_key;

    //mountain east of the fount
    for (int i = 58; i <= 61; i++) {
        for (int j = 18; j <= 25; j++) {
            map[i][j] = wall_key;
        }
    }

    //water in waterway
    map[43][31] = water_key;
    map[44][31] = water_key;
    map[45][31] = water_key;
    map[46][31] = water_key;
    map[47][31] = water_key;
    map[48][31] = water_key;
    map[49][31] = water_key;
    for (int i = 39; i <= 51; i++) {
        map[i][32] = water_key;
    }
    for (int i = 36; i <= 53; i++) {
        map[i][33] = water_key;
    }
    for (int i = 34; i <= 54; i++) {
        map[i][34] = water_key;
    }
    for (int i = 31; i <= 54; i++) {
        map[i][35] = water_key;
    }
    for (int i = 30; i <= 55; i++) {
        map[i][36] = water_key;
    }
    for (int i = 29; i <= 56; i++) {
        map[i][37] = water_key;
    }
    for (int i = 29; i <= 56; i++) {
        map[i][38] = water_key;
    }
    for (int i = 27; i <= 57; i++) {
        map[i][39] = water_key;
    }
    for (int i = 26; i <= 57; i++) {
        map[i][40] = water_key;
    }
    for (int i = 25; i <= 58; i++) {
        map[i][41] = water_key;
    }

    //teleports
    map[46][27] = wall_key;
    map[45][27] = wall_key;
    map[45][28] = wall_key;
    map[33][13] = teleport_key;
    map[46][28] = teleport_key;

    //       ===building shapes===
    //regalia
    map[34][12] = "|‾‾";
    map[35][12] = "‾‾‾";
    map[36][12] = "‾‾|";
    map[38][12] = "|‾‾";
    map[29][11] = "  |";
    map[31][11] = "|__";
    map[32][11] = "__|";
    map[28][10] = "‾‾‾";
    map[29][10] = "‾‾|";
    map[31][10] = "|‾‾";
    map[32][10] = "‾‾|";
    map[34][10] = "|_‾";
    map[35][10] = "___";
    map[36][10] = "__|";
    map[38][10] = "|__";
    map[39][10] = "___";
    map[26][9]  = "  |";
    map[35][9]  ="|‾‾";
    map[36][9]  = "‾‾|";
    map[38][9]  = "|‾‾";
    map[39][9]  = "‾‾‾";
    map[40][9]  = "‾‾‾";
    map[26][8]  = "  |";
    map[28][8]  = "|__";
    map[29][8]  = "__|";
    map[31][8]  = "|__";
    map[32][8]  = "___";
    map[33][8]  = "__|";
    map[26][7]  = "  |";
    map[28][7]  = "|  ";
    map[29][7]  = "  |";
    map[37][7]  = "___";
    map[38][7]  = "___";
    map[39][7]  = "__|";
    map[26][6]  = "  |";
    map[28][6]  = "|‾‾";
    map[29][6]  = "‾‾|";
    map[31][6]  = "|‾‾";
    map[32][6]  = "‾‾|";
    map[36][6]  = "|‾‾";
    map[37][6]  = "‾‾‾";
    map[38][6]  = "‾‾‾";
    map[39][6]  = "‾‾|";
    map[26][5]  = "  |";
    map[29][5]  = "╚==";
    for (int i = 30; i <= 37; i++) {
        map[i][5] = "===";
    }
    map[38][5] = "==╝";
    map[29][4] = "|| ";
    map[38][4] = " ||";
    map[39][4] = "|__";
    map[40][4] = "___";
    map[29][3] = "|| ";
    map[38][3] = " ||";
    map[39][3] = "|  ";


    //          ===labels===
    //regalia
    map[30][7] = " R ";
    map[31][7] = "|E ";
    map[32][7] = "‾G‾";
    map[33][7] = "‾A_";
    map[34][7] = "|L ";
    map[35][7] = "|I_";
    map[36][7] = "_A_";

    return "done";
}
