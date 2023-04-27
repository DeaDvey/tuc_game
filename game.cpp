#include <iostream>
#include <iostream>
#include <fstream> // for file input/output
#include <string> // for string operations
#include <algorithm> 
#include <string>  
#include <cstring>
//using namespace std;

void saveToFile(const std::string& fileName,
                const std::string& species,
                const bool valid_species,
                const std::string& first_pronoun,
                const std::string& second_pronoun,
                const std::string& name,
                const int state)
{
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << species << std::endl;
        outFile << valid_species << std::endl;
        outFile << first_pronoun << std::endl;
        outFile << second_pronoun << std::endl;
        outFile << name << std::endl;
        outFile << state << std::endl;
        outFile.close();
    }
    else {
        std::cout << "Error: could not save to file" << std::endl;
    }
}


void loadFromFile(const std::string& fileName,
                  std::string& species,
                  bool& valid_species,
                  std::string& first_pronoun,
                  std::string& second_pronoun,
                  std::string& name,
                  int& state)
{
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        inFile >> species;
        inFile >> valid_species;
        inFile >> first_pronoun;
        inFile >> second_pronoun;
        inFile >> name;
        inFile >> state;
        inFile.close();
    }
    else {
        std::cout << "Error: could not load from file" << std::endl;
    }
}

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
	//variables//
	std::string species; //define species as null
	bool valid_species = false;
	std::string first_pronoun;
	std::string second_pronoun;
	std::string name;
	int state = 0;
	//variables//
	
	// check if save file exists, and load variables from it
	const std::string saveFileName = "save.txt";
	std::ifstream saveFile(saveFileName);
	if (saveFile.good()) {
        	loadFromFile(saveFileName, species, valid_species, first_pronoun, second_pronoun, name, state);//load variables from file
	}

	
	std::cout << "---Welcome to your TUC adventure!---" << "\n";
	
	//character setup state
	if (state == 0) {	
		//User inputs species, loops if invalid
		while (valid_species == false) {
			std::cout << "Input character species (Overlander/Underlander/Gnawer): " << "\n";
			std::cin >> species;
			//std::cout << species << "\n";
			if (species == "Underlander" || species == "Overlander" || species == "Gnawer") {
				std::cout << "Valid species" << "\n";
				valid_species = true;
			}	
			else {
				std::cout << "Invalid species, reinput" << "\n";
				valid_species = false;
			}
		}
		
		//get name and pronouns and save to variables
		std::cout << "Enter your first pronoun, for example they, he or she: " << "\n";
		std::cin >> first_pronoun;
		std::cout << "Enter your second pronoun,, for example them, him or her: " << "\n";
		std::cin >> second_pronoun;
		std::cout << "And finally, enter your characters name: " << "\n";
		std::cin >> name;
		state = 1;
		saveToFile(saveFileName, species, valid_species, first_pronoun, second_pronoun, name, state); //save data
	}


	//Skip tutorial?
	if (state == 1) {
		//Find out if user wants to just skip into main game
		std::string play_tutorial;
		std::cout << "Play the tutorial?(y/n) " << "\n";
		std::cin >> play_tutorial;
		if (play_tutorial == "n") {
			std::cout << "Ok, that's fine.  You will be placed in your starting location" << "\n";
			state = 2;
			
		}
		else if (play_tutorial == "y") {
			std::cout << "Welcome to the tutorial" << "\n";
			
		}
	}
	//Tutorial state
	if (state == 1) {
		
	
		//tutorial start
		if (species == "Underlander") {
			std::cout << "'Wake up " << name << ", The Gnawers are attacking, we must escape on the Fliers'" << "\n";
		}
		if (species == "Overlander") {
			std::cout << "'Who are you, who are' you hear a high pitched voice say suddenly. What had happened you ask yourself, the last thin you remember was falling... forever, then everything went black" << "\n";
		}
		if (species == "Gnawer") {
			std::cout << "'Quick, get up " << name << " The Bane is saying we attack the human outpost in 15 minutes, get up!'" << "\n";
		}
		state = 2;//change state to main state
	}
	return 0;
}
