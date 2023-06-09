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

std::string character_setup(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }

    //color codes used during text
    std::string fatal_error_color = "\033[31m";
    std::string error_color = "\033[33m";
    std::string dialouge_color = "\033[3;32m";
    std::string command_info_color = "\033[34m";
    std::string general_color = "\033[0m";

    

    //output
    std::cout << "I see you have no character, lets make one!" << "\n";


    //User inputs species, loops if invalid
    while (data[key["valid_species"]].second == "false") {
        std::cout << "Input character species (Overlander/Underlander/Gnawer): " << "\n";
        std::cin >> data[key["species"]].second;

        //checks if valid
        if (data[key["species"]].second == "Underlander" || data[key["species"]].second == "Overlander" ||data[key["species"]].second == "Gnawer") {
            std::cout << "Valid species" << "\n";
            data[key["valid_species"]].second = true;
        }
        //else it isn't valid so loops
        else {
	  std::cout << error_color << "Invalid species, reinput" << general_color << "\n";
            data[key["valid_species"]].second = false;
        }
    }


    //get name and pronouns and save to variables
    //first pronoun
    std::cout << "Enter your first pronoun, for example they, he or she: " << "\n";
    std::cin >> data[key["first_pronoun"]].second;
    //second pronoun
    std::cout << "Enter your second pronoun,, for example them, him or her: " << "\n";
    std::cin >> data[key["second_pronoun"]].second;


    //name
    std::cout << "And finally, enter your characters name: " << "\n";
    std::cin >> data[key["name"]].second;
    //set location
    data[key["location_x"]].second = "34";
    data[key["location_y"]].second = "6";


    //set state to tutorial skip option
    data[key["state"]].second = "main";

    if (data[key["species"]].second == "Overlander") {
		  data[key["inventory"]].second += "torch ";
    }
    if (data[key["species"]].second == "Underlander") {
      data[key["inventory"]].second += "sword ";
    }
    if (data[key["species"]].second == "Gnawer") {
      data[key["inventory"]].second += "";
    }
    
    
    saveToFile(saveFileName, data); //save data



    
    return "done";
}
