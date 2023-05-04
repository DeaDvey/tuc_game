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

std::string map_defenitions(std::string map[100][114]) {
    std::string wall_key =     "|||";
    std::string water_key =    "≈≈≈";
    std::string teleport_key = " ⌂ ";


    //regalia
    map[31][101] = wall_key;
    map[32][101] = wall_key;
    map[33][101] = wall_key;
    map[34][101] = wall_key;
    map[34][101] = wall_key;
    map[35][101] = wall_key;
    map[36][102] = wall_key;
    map[37][102] = wall_key;
    map[38][102] = wall_key;
    map[39][102] = wall_key;
    map[40][103] = wall_key;
    map[41][104] = wall_key;
    map[41][105] = wall_key;
    map[42][106] = wall_key;
    map[41][107] = wall_key;
    map[41][108] = wall_key;
    map[41][109] = wall_key;
    map[41][110] = wall_key;
    map[40][111] = wall_key;
    map[39][112] = wall_key;
    map[38][113] = wall_key;
    map[37][113] = wall_key;
    map[36][113] = wall_key;
    map[35][113] = wall_key;
    map[34][113] = wall_key;
    //[33][13] is a teleport block
    map[32][113] = wall_key;
    map[31][113] = wall_key;
    map[30][112] = wall_key;
    map[29][112] = wall_key;
    map[28][111] = wall_key;
    map[27][110] = wall_key;
    map[26][110] = wall_key;
    map[25][109] = wall_key;
    map[25][108] = wall_key;
    map[25][107] = wall_key;
    map[25][106] = wall_key;
    map[25][105] = wall_key;
    map[26][104] = wall_key;
    map[27][103] = wall_key;
    map[28][102] = wall_key;
    map[29][102] = wall_key;
    map[30][102] = wall_key;

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
    map[32][19] = wall_key;
    map[32][18] = wall_key;
    map[32][17] = wall_key;
    map[31][18] = wall_key;
    map[31][17] = wall_key;

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
    map[34][112] = "|‾‾";
    map[35][112] = "‾‾‾";
    map[36][112] = "‾‾|";
    map[38][112] = "|‾‾";
    map[29][111] = "  |";
    map[31][111] = "|__";
    map[32][111] = "__|";
    map[28][110] = "‾‾‾";
    map[29][110] = "‾‾|";
    map[31][110] = "|‾‾";
    map[32][110] = "‾‾|";
    map[34][110] = "|_‾";
    map[35][110] = "___";
    map[36][110] = "__|";
    map[38][110] = "|__";
    map[39][110] = "___";
    map[26][109]  = "  |";
    map[35][109]  ="|‾‾";
    map[36][109]  = "‾‾|";
    map[38][109]  = "|‾‾";
    map[39][109]  = "‾‾‾";
    map[40][109]  = "‾‾‾";
    map[26][108]  = "  |";
    map[28][108]  = "|__";
    map[29][108]  = "__|";
    map[31][108]  = "|__";
    map[32][108]  = "___";
    map[33][108]  = "__|";
    map[26][107]  = "  |";
    map[28][107]  = "|  ";
    map[29][107]  = "  |";
    map[37][107]  = "___";
    map[38][107]  = "___";
    map[39][107]  = "__|";
    map[26][106]  = "  |";
    map[28][106]  = "|‾‾";
    map[29][106]  = "‾‾|";
    map[31][106]  = "|‾‾";
    map[32][106]  = "‾‾|";
    map[36][106]  = "|‾‾";
    map[37][106]  = "‾‾‾";
    map[38][106]  = "‾‾‾";
    map[39][106]  = "‾‾|";
    map[26][105]  = "  |";
    map[29][105]  = "╚==";
    for (int i = 30; i <= 37; i++) {
        map[i][105] = "===";
    }
    map[38][105] = "==╝";
    map[29][104] = "|| ";
    map[38][104] = " ||";
    map[39][104] = "|__";
    map[40][104] = "___";
    map[29][103] = "|| ";
    map[38][103] = " ||";
    map[39][103] = "|  ";


    //          ===labels===
    //regalia
    map[30][107] = " R ";
    map[31][107] = "|E ";
    map[32][107] = "‾G‾";
    map[33][107] = "‾A_";
    map[34][107] = "|L ";
    map[35][107] = "|I_";
    map[36][107] = "_A_";

    return "done";
}
