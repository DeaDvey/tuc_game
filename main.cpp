//Color code key:
//Red =              Fatal error
//Yellow =           Error
//Blue =             Tell user about command
//Green+italics =    Dialouge
//White =            Rest/narator

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
#include <chrono>
#include <thread>


int main() {
    //clear screen on program start
	#ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif


	//              ===VARIABLES===

	std::vector<std::pair<std::string, std::string>> data { // main data veriable for character data, this is what gets saved
        {"species", " "},
        {"valid_species", "false"},
        {"first_pronoun", " "},
        {"second_pronoun", " "},
        {"name", " "},
        {"state", "setup"},
        {"location_x", "0"},
        {"location_y", "0"},
        {"physical_position", "standing"},
	{"inventory", ""} 
    };

	std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }

    //color codes
    std::string fatal_error_color = "\033[31m";
    std::string error_color = "\033[33m";
    std::string dialouge_color = "\033[3;32m";
    std::string command_info_color = "\033[34m";
    std::string general_color = "\033[0m";

    //save file, changes if multiple characters, not yet implemented multiple characters
    const std::string saveFileName = "save.txt";
	//              ===VARIABLES===




	// check if save file exists, and load variables from it into the data vector
	std::ifstream saveFile(saveFileName);
	if (saveFile.good()) {
        	loadFromFile(saveFileName, data);//load variables from file
	}


	//debugging, uncomment to print all variables//
	// std::cout << data[key["species"]].second << "\n";
	// std::cout << data[key["valid_species"]].second << "\n";
	// std::cout << data[key["first_pronoun"]].second << "/";
	// std::cout << data[key["second_pronoun"]].second << "\n";
	// std::cout << data[key["name"]].second << "\n";
	// std::cout << data[key["state"]].second << "\n";

	//rat ascii art
	std::cout << "                _..----.._    _" << "\n";
	std::cout << "             .`  .--.    ''-.(0)_" << "\n";
	std::cout << "'-.__.-''''=:|   ,  _)_ \\__ . c\'-.." << "\n";
	std::cout << "             '''------'---''---'-''" << "\n\n"; //I found this rat art on https://ascii.co.uk/art/rat

	std::cout << "---Welcome to your TUC adventure!---" << "\n\n"; //welcome speach said on all loads


        

	
	
	//                          ===character setup state===
	if (data[key["state"]].second == "setup") {
        character_setup(data, saveFileName);
        std::cout << "------------------------" << "\n";
	}

	//                          ===Skip tutorial?===
	if (data[key["state"]].second == "skip_tutorial") {
		//Find out if user wants to just skip into main game
		std::string play_tutorial;
		std::cout << "Play the tutorial?(y/n) " << "\n";
		std::cin >> play_tutorial;

        //if the user wants to skip, asign state as main
		if (play_tutorial == "n") {
			std::cout << "Ok, that's fine.  You will be placed in your starting location" << "\n";
			data[key["state"]].second = "main";

		}

		//if use wants to contnue with tutorial, change state to tutorial
		else if (play_tutorial == "y") {
			std::cout << "Welcome to the tutorial" << "\n";
            data[key["state"]].second = "tutorial";

		}


		saveToFile(saveFileName, data); //save data
	}

	// Create a new thread to run the loop
	std::thread loop_thread(run_loop);


	//                          ===Tutorial state===
	if (data[key["state"]].second == "tutorial") {

        tutorial(data, saveFileName);
        saveToFile(saveFileName, data); //save data
	}


	//                          ===main game===
	if (data[key["state"]].second == "main") {
        game(data, saveFileName);
        return 0;
	}



	//else check, if state is invalid
	else if (data[key["state"]].second != "setup" && data[key["state"]].second != "tutorial" && data[key["state"]].second != "main") { //lets up know if state has a corrupted value
            std::cout << "\033[31m";

			std::cout << "state is messed up bruh" << "\n";
            std::cout << "\033[0m";
			return 1;
	}


	std::cout << " " << "\n";
	return 0;
}
