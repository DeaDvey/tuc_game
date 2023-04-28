#include <iostream>
#include <iostream>
#include <fstream> // for file input/output
#include <string> // for string operations
#include <algorithm> 
#include <string>  
#include <cstring>
#include <map>//map variables
#include <cstdlib>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
//using namespace std;
//test

//save data into savefile
void saveToFile(const std::string& fileName, const std::map<std::string, std::string>& data)
{
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (const auto& [key, val] : data) {
            outFile << key << "=" << val << std::endl;
        }
        outFile.close();
    }
    else {
        std::cout << "Error: could not save to file" << std::endl;
    }
}

//load variables in data from save file
void loadFromFile(const std::string& fileName, std::map<std::string, std::string>& data) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        for (auto& [key, value] : data) {
            inFile >> key >> value;
        }
        inFile.close();
    }
    else {
        std::cout << "Error: could not load from file" << std::endl;
    }
}

//function to convert word to uppercase
char* to_uppercase(const char* str) {
    size_t len = strlen(str);
    char* upper_str = new char[len + 1];
    for (size_t i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            upper_str[i] = toupper(str[i]);
        } else {
            upper_str[i] = str[i];
        }
    }
    upper_str[len] = '\0';
    return upper_str;
}

int main() {
	#ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif


	//variables//
	std::vector<std::pair<std::string, std::string>> data {
        {"species", " "},
        {"valid_species", "false"},
        {"first_pronoun", " "},
        {"second_pronoun", " "},
        {"name", " "},
        {"state", "setup"},
        {"location", " "}
    };

	std::map<std::string, int> key;
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }
	//variables//

	// check if save file exists, and load variables from it
	const std::string saveFileName = "save.txt";
	std::ifstream saveFile(saveFileName);
	if (saveFile.good()) {
        	loadFromFile(saveFileName, data);//load variables from file
	}

	//debugging//
	std::cout << data[key["species"]] << "\n";
	std::cout << data[key["valid_species"]] << "\n";
	std::cout << data[key["first_pronoun"]] << "/";
	std::cout << data[key["second_pronoun"]] << "\n";
	std::cout << data[key["name"]] << "\n";
	std::cout << data[key["state"]] << "\n";

	//rat ascii art
	std::cout << "               _..----.._    _" << "\n";
	std::cout << "            .`  .--.    ''-.(0)_" << "\n";
	std::cout << "'-.__.-''''=:|   ,  _)_ \\__ . c\'-.." << "\n";
	std::cout << "             '''------'---''---'-''" << "\n\n"; //I found this rat art on https://ascii.co.uk/art/rat


	std::cout << "---Welcome to your TUC adventure!---" << "\n"; //welcome speach said on all loads
	
	//character setup state
	if (data[key["state"]] == "setup") {
		std::cout << "I see you have no character, lets make one!" << "\n";
		//User inputs species, loops if invalid
		while (data[key["valid_species"]] == "false") {
			std::cout << "Input character species (Overlander/Underlander/Gnawer): " << "\n";
			std::cin >> data[key["species"]];
			//std::cout << species << "\n";
			if (data[key["species"]] == "Underlander" || data[key["species"]] == "Overlander" || data[key["species"]] == "Gnawer") {
				std::cout << "Valid species" << "\n";
				data[key["valid_species"]] = true;
			}	
			else {
				std::cout << "Invalid species, reinput" << "\n";
				data[key["valid_species"]] = false;
			}
		}
		
		//get name and pronouns and save to variables
		std::cout << "Enter your first pronoun, for example they, he or she: " << "\n";
		std::cin >> data[key["first_pronoun"]];
		std::cout << "Enter your second pronoun,, for example them, him or her: " << "\n";
		std::cin >> data[key["second_pronoun"]];
		std::cout << "And finally, enter your characters name: " << "\n";
		std::cin >> data[key["name"]];
		data["state"] = "tutorial";
		saveToFile(saveFileName, data); //save data
	}


	//Skip tutorial?
	if (data[key["state"]] == "tutorial") {
		//Find out if user wants to just skip into main game
		std::string play_tutorial;
		std::cout << "Play the tutorial?(y/n) " << "\n";
		std::cin >> play_tutorial;
		if (play_tutorial == "n") {
			std::cout << "Ok, that's fine.  You will be placed in your starting location" << "\n";
			data[key["state"]] = "main";
			
		}
		else if (play_tutorial == "y") {
			std::cout << "Welcome to the tutorial" << "\n";
			
		}
		saveToFile(saveFileName, data); //save data
	}
	//Tutorial state
	if (data[key["state"]] == "tutorial") {
		
	
		//tutorial start
		//Underlander tutorial
		if (data[key["species"]] == "Underlander") {
			data[key["location"]] = "Human Outpost 1";
			std::cout << "'Wake up " << data[key["name"]] << ", The Gnawers are attacking, we must escape on the Fliers'" << "\n";
			system("Color ED");
			std::cout << "colour test";
		}

		//Overlander tutorial
		if (data[key["species"]] == "Overlander") {
			data[key["location"]] = "Overland Gateway";
			std::cout << "'Who are you, who are' you hear a high pitched voice say suddenly. What had happened you ask yourself, the last thin you remember was falling... forever, then everything went black" << "\n";
		}


		//Gnawer tutorial
		if (data[key["species"]] == "Gnawer") {
			data[key["location"]] = "Human Outpost";
			std::cout << "'Quick, get up " << data[key["name"]] << " The Bane is saying we attack the human outpost in 15 minutes, get up!'" << "\n";
		}
		data[key["state"]] = "main";//change state to main state
		saveToFile(saveFileName, data); //save data
	}

	//main game
	if (data[key["state"]] == "main") {
		std::cout << "Main game not yet made :(" << "\n";
	}

	//else
	else if (data[key["state"]] != "setup" && data[key["state"]] != "tutorial" && data[key["state"]] != "main") { //lets up know if state has a corrupted value
			std::cout << "state is messed up bruh" << "\n";
	}


	std::cout << " " << "\n";
	return 0;
}
