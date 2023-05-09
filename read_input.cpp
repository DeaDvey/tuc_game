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


//                        ===read user input and determine the output===
std::string readInput(std::string& input, std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) { // this function esentially recieves an input and determines where to send the user, a middle man
    //variables
    std::cout << "\n"; //seperate up input and output

    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }

    std::string output;//set what should be outputted
    input = lower(input);

    //color codes
    std::string fatal_error_color = "\033[31m";
    std::string error_color = "\033[33m";
    std::string dialouge_color = "\033[3;32m";
    std::string command_info_color = "\033[34m";
    std::string general_color = "\033[0m";
    //variables ^^



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

    //saving
    else if (input == "save") {
        saveToFile(saveFileName, data);
        std::cout << "Game saved" << "\n";
    }

    //credits for game designers/helpers/contrbuters
    else if (input == "credit" || input == "credits") {
        std::cout << "• DeaDvey - contributer and project leader" << "\n";
        std::cout << "• Presley - designed original map used to create pixel map" << "\n";
    }

    //print info/specific info for the character
    else if (input == "info" || input == "information") {
        //print all the variables
        std::cout << "Species: " << data[key["species"]].second << "\n";
        std::cout << "Pronouns: " << data[key["first_pronoun"]].second << "/";
        std::cout << data[key["second_pronoun"]].second << "\n";
        std::cout << "Name: " << data[key["name"]].second << "\n";
        std::cout << "State: " << data[key["state"]].second << "\n";
        std::cout << "Location: " << data[key["location_x"]].second << ", " << data[key["location_y"]].second << "\n";
        std::cout << "Physical position: " << data[key["physical_position"]].second << "\n";
	std::cout << "inventory: " << data[key["inventory"]].second << "\n";
    }

    //help the user by giving them commands info
    else if (input == "help") {
        std::cout << "See resources/tucgame.html for commands" << "\n";
        std::cout << "It looks best in a web browser display" << "\n";
    }

    //traveling around map, north, south, east and west
    else if ((input == "n" || input == "north") && data[key["physical_position"]].second == "standing") {
        travel("north", data, saveFileName);
    }
    else if ((input == "s" || input == "south") && data[key["physical_position"]].second == "standing") {
        travel("south", data, saveFileName);
    }
    else if ((input == "e" || input == "east") && data[key["physical_position"]].second == "standing") {
        travel("east", data, saveFileName);
    }
    else if ((input == "w" || input == "west") && data[key["physical_position"]].second == "standing") {
        travel("west", data, saveFileName);
    }
    else if ((input == "w" || input == "west" || input == "e" || input == "east" || input == "s" || input == "south" || input == "n" || input == "north") && data[key["physical_position"]].second != "standing") {
        std::cout << "You must be standing in order to travel 🤦" << "\n";
        std::cout << command_info_color << "stand" << general_color << " to stand" << "\n";
    }

    //print map on screen
    else if (input == "map") {
        display_map(data, saveFileName);
    }

    //talk to the global chat
    else if (input.substr(0, 4) == "talk") { // find if the first 4 chracters are talk
      std::string message = input.substr(5);//get the actual message
      //std::cout << message << "\n";
      talk(message, data);
    }
    else if (input.substr(0, 3) == "say") { // find if the first 3 chracters are say
      std::string message = input.substr(4);//get the actual message
      //std::cout << message << "\n";
      talk(message, data);
    }

    //display inventory
    else if (input == "inventory" || input == "inv") {
      return_inventory_array(data, saveFileName);
    }



    //else tell user they must of typoed
    else {
        std::cout << "Sorry, this command does not exist, or does not currently work, please check your spelling and check it is a valid command given your situation" << "\n";
    }

    std::cout << "\n"; //seperate up input and output

    saveToFile(saveFileName, data); //save data
    return output;
}
