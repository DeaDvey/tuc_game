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


//                       ===save data into savefile===
void saveToFile(const std::string& fileName, const std::vector<std::pair<std::string, std::string>>& data)
{
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (const auto& [key, val] : data) {
            outFile << val << std::endl;
        }
        outFile.close();
    }
    else {
        std::cout << "Error: could not save to file" << std::endl;
    }
}

//                        ===load variables in data from save file===
void loadFromFile(const std::string& fileName, std::vector<std::pair<std::string, std::string>>& data) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        int i = 0;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string value;
            if (std::getline(iss, value)) {
                data[i].second = value;
                i++;
            }
        }
        inFile.close();
    }
    else {
        std::cout << "Error: could not load from file" << std::endl;
    }
}

//                        ===read user input and determine the output===
std::string readInput(const std::string& input, std::vector<std::pair<std::string, std::string>>& data) {

    std::cout << "\n"; //seperate up input and output

    std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }

    std::string output;//set what should be outputted

    //change phyisical position (sitting/standing/laying)
    //standing
    if (input == "stand" || input == "standing") {
        data[key["physical_position"]].second = "standing";
        std::cout << "You are now standing" << "\n";
    }
    //sitting
    if (input == "sit" || input == "sitting") {
        data[key["physical_position"]].second = "sitting";
        std::cout << "You are now sitting" << "\n";
    }
    //laying
    if (input == "lay" || input == "lie" || input == "laying" || input == "lying") {
        data[key["physical_position"]].second = "lying";
        std::cout << "You are now lying down" << "\n";
    }

    //print info/specific info
    if (input == "info" || input == "information") {
        std::cout << "Species: " << data[key["species"]].second << "\n";
        std::cout << "Pronouns: " << data[key["first_pronoun"]].second << "/";
        std::cout << data[key["second_pronoun"]].second << "\n";
        std::cout << "Name: " << data[key["name"]].second << "\n";
        std::cout << "State: " << data[key["state"]].second << "\n";
        std::cout << "Location: " << data[key["location"]].second << "\n";
    }

    //help the user
    if (input == "help") {
        std::cout << "See commands.html for commands" << "\n";
    }

    //else tell user they must of typoed
    else {
        std::cout << "Sorry, this command does not exist, please check your spelling and check it is a valid command" << "\n";
    }

    std::cout << "\n"; //seperate up input and output

    return output;
}

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
        {"location", " "},
        {"physical_position", "standing"}
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
	//              ===VARIABLES===




	// check if save file exists, and load variables from it into the data vector
	const std::string saveFileName = "save.txt";
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
        //output
		std::cout << "I see you have no character, lets make one!" << "\n";


		//User inputs species, loops if invalid
		while (data[key["valid_species"]].second == "false") {
			std::cout << "Input character species (Overlander/Underlander/Gnawer): " << "\n";
			std::cin >> data[key["species"]].second;

            //checks if valid
			if (data[key["species"]].second == "Underlander" || data[key["species"]].second == "Overlander" || data[key["species"]].second == "Gnawer") {
				std::cout << "Valid species" << "\n";
				data[key["valid_species"]].second = true;
			}

			//else it isn't valid so loops
			else {
				std::cout << "Invalid species, reinput" << "\n";
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

        //set state to tutorial skip option
		data[key["state"]].second = "main";

		saveToFile(saveFileName, data); //save data
	}


	//                         ===Skip tutorial?===
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


	//                          ===Tutorial state===
	if (data[key["state"]].second == "tutorial") {
        std::string tutorial_finished = "false";

		//tutorial start




		//Underlander tutorial
		if (data[key["species"]].second == "Underlander") {
			data[key["location"]].second = "Human Outpost 1";
            //output text
			std::cout << dialouge_color << "'Wake up " << data[key["name"]].second << ", The Gnawers are attacking, we must escape on the Fliers'" << general_color << "\n";
            data[key["physical_position"]].second = "lying";
		}

		//Overlander tutorial
		if (data[key["species"]].second == "Overlander") {
			data[key["location"]].second = "Overland Gateway";

            //output text
			std::cout << dialouge_color << "'Who are you, who are'";
            std::cout << general_color << "you hear a high pitched voice say suddenly. What had happened you ask yourself, the last thin you remember was falling... forever, then everything went black" << "\n";
            std::cout << command_info_color << "Type 'stand' to stand up" << general_color << "\n";
            data[key["physical_position"]].second = "sitting";
		}


		//Gnawer tutorial
		if (data[key["species"]].second == "Gnawer") {
			data[key["location"]].second = "Human Outpost";
            //output text
			std::cout << dialouge_color << "'Quick, get up " << data[key["name"]].second << " The Bane is saying we attack the human outpost in 15 minutes, get up!'" << general_color << "\n";
            data[key["physical_position"]].second = "lying";
		}





		//check if tutorial is finished
		if (tutorial_finished == "true") {
            std::cout << "finished tutorial!" << "\n";
            data[key["state"]].second = "main";//change state to main state
        }
		saveToFile(saveFileName, data); //save data
	}


	//                                   ===main game===
	if (data[key["state"]].second == "main") {
        std::string input;
        std::string continue_loop = "true";
		std::cout << "-See commands.html for commands-" << "\n\n";
        while (continue_loop == "true") {//infinite loop until exit is typed
            std::cout << ">> ";
            std::cin >> input;

            //if input is exit, save and end the program
            if (input == "exit") {
                saveToFile(saveFileName, data); //save data
                std::cout << "\nExiting\n";
                return 0;
            }
            //else, read the input
            else {
                readInput(input, data);
            }
        }
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
