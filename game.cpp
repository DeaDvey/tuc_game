#include <iostream>
#include <iostream>
#include <fstream> // for file input/output
#include <string> // for string operations
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
        	loadFromFile(saveFileName, species, valid_species, first_pronoun, second_pronoun, name, state);
	}

	//setup character
	std::cout << "---Welcome to your TUC adventure!---" << "\n";

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
		saveToFile(saveFileName, species, valid_species, first_pronoun, second_pronoun, name, state);
	}
	if (state == 1) {
		if (species == "Underlander") {
			std::cout << "'Wake up " << name << ", The Gnawers are attacking, we must escape on the Fliers'" << "\n";
		}
		if (species == "Overlander") {
			std::cout << "'Who are you, who are' you hear a high pitched voice say suddenly. What had happened you ask yourself, the last thin you remember was falling... forever, then everything went black" << "\n";
		}
		if (species == "Gnawer") {
			std::cout << "'Quick, get up " << name << " The Bane is saying we attack the human outpost in 15 minutes, get up!'" << "\n";
		}
	}
	return 0;
}
