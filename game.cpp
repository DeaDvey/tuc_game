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
        {"location", " "}
    };

	std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }
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


	std::cout << "---Welcome to your TUC adventure!---" << "\n"; //welcome speach said on all loads
	
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

        //set state to tutorial
		data[key["state"]].second = "tutorial";

		saveToFile(saveFileName, data); //save data
	}


	//                ===Skip tutorial?===
	if (data[key["state"]].second == "tutorial") {
		//Find out if user wants to just skip into main game
		std::string play_tutorial;
		std::cout << "Play the tutorial?(y/n) " << "\n";
		std::cin >> play_tutorial;

        //if the user wants to skip, asign state as main
		if (play_tutorial == "n") {
			std::cout << "Ok, that's fine.  You will be placed in your starting location" << "\n";
			data[key["state"]].second = "main";

		}

		//if use wants to contnue with tutorial, dont change state
		else if (play_tutorial == "y") {
			std::cout << "Welcome to the tutorial" << "\n";

		}


		saveToFile(saveFileName, data); //save data
	}


	//                          ===Tutorial state===
	if (data[key["state"]].second == "tutorial") {


		//tutorial start
		//Underlander tutorial
		if (data[key["species"]].second == "Underlander") {
			data[key["location"]].second = "Human Outpost 1";
			std::cout << "'Wake up " << data[key["name"]].second << ", The Gnawers are attacking, we must escape on the Fliers'" << "\n";
			system("Color ED");
			std::cout << "colour test";
		}

		//Overlander tutorial
		if (data[key["species"]].second == "Overlander") {
			data[key["location"]].second = "Overland Gateway";
			std::cout << "'Who are you, who are' you hear a high pitched voice say suddenly. What had happened you ask yourself, the last thin you remember was falling... forever, then everything went black" << "\n";
		}


		//Gnawer tutorial
		if (data[key["species"]].second == "Gnawer") {
			data[key["location"]].second = "Human Outpost";
			std::cout << "'Quick, get up " << data[key["name"]].second << " The Bane is saying we attack the human outpost in 15 minutes, get up!'" << "\n";
		}
		data[key["state"]].second = "main";//change state to main state
		saveToFile(saveFileName, data); //save data
	}






	//                                   ===main game===
	if (data[key["state"]].second == "main") {
		std::cout << "Main game not yet made :(" << "\n";
	}

	//else check, if state is invalid
	else if (data[key["state"]].second != "setup" && data[key["state"]].second != "tutorial" && data[key["state"]].second != "main") { //lets up know if state has a corrupted value
			std::cout << "state is messed up bruh" << "\n";
			return 1;
	}


	std::cout << " " << "\n";
	return 0;
}
