#include <iostream>
#include <iostream>
#include <fstream> // for file input/output
#include <string> // for string operations
#include <algorithm> 
#include <string>  
#include <cstring>
#include <map>//map variables
#include <cstdlib>
//using namespace std;

//save data into savefile
void saveToFile(const std::string& fileName, const std::map<std::string, std::string>& data)
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

//load variables in data from save file
void loadFromFile(const std::string& fileName, std::map<std::string, std::string>& data) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        for (auto& [key, value] : data) {
            inFile >> value;
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
	std::map<std::string, std::string> data = {
        {"species", " "},
        {"valid_species", "false"},
        {"first_pronoun", " "},
        {"second_pronoun", " "},
        {"name", " "},
        {"state", "setup"}
    };
	//variables//

	// check if save file exists, and load variables from it
	const std::string saveFileName = "save.txt";
	std::ifstream saveFile(saveFileName);
	if (saveFile.good()) {
        	loadFromFile(saveFileName, data);//load variables from file
	}

	//debugging//
	std::cout << data["species"] << "\n";
	std::cout << data["valid_species"] << "\n";
	std::cout << data["first_pronoun"] << "/";
	std::cout << data["second_pronoun"] << "\n";
	std::cout << data["name"] << "\n";
	std::cout << data["state"] << "\n";
	


	std::cout << "---Welcome to your TUC adventure!---" << "\n"; //welcome speach said on all loads
	
	//character setup state
	if (data["state"] == "setup") {
		std::cout << "I see you have no character, lets make one!" << "\n";
		//User inputs species, loops if invalid
		while (data["valid_species"] == "false") {
			std::cout << "Input character species (Overlander/Underlander/Gnawer): " << "\n";
			std::cin >> data["species"];
			//std::cout << species << "\n";
			if (data["species"] == "Underlander" || data["species"] == "Overlander" || data["species"] == "Gnawer") {
				std::cout << "Valid species" << "\n";
				data["valid_species"] = true;
			}	
			else {
				std::cout << "Invalid species, reinput" << "\n";
				data["valid_species"] = false;
			}
		}
		
		//get name and pronouns and save to variables
		std::cout << "Enter your first pronoun, for example they, he or she: " << "\n";
		std::cin >> data["first_pronoun"];
		std::cout << "Enter your second pronoun,, for example them, him or her: " << "\n";
		std::cin >> data["second_pronoun"];
		std::cout << "And finally, enter your characters name: " << "\n";
		std::cin >> data["name"];
		data["state"] = "tutorial";
		saveToFile(saveFileName, data); //save data
	}


	//Skip tutorial?
	if (data["state"] == "tutorial") {
		//Find out if user wants to just skip into main game
		std::string play_tutorial;
		std::cout << "Play the tutorial?(y/n) " << "\n";
		std::cin >> play_tutorial;
		if (play_tutorial == "n") {
			std::cout << "Ok, that's fine.  You will be placed in your starting location" << "\n";
			data["state"] = "main";
			
		}
		else if (play_tutorial == "y") {
			std::cout << "Welcome to the tutorial" << "\n";
			
		}
		saveToFile(saveFileName, data); //save data
	}
	//Tutorial state
	if (data["state"] == "tutorial") {
		
	
		//tutorial start
		if (data["species"] == "Underlander") {
			std::cout << "'Wake up " << data["name"] << ", The Gnawers are attacking, we must escape on the Fliers'" << "\n";
		}
		if (data["species"] == "Overlander") {
			std::cout << "'Who are you, who are' you hear a high pitched voice say suddenly. What had happened you ask yourself, the last thin you remember was falling... forever, then everything went black" << "\n";
		}
		if (data["species"] == "Gnawer") {
			std::cout << "'Quick, get up " << data["name"] << " The Bane is saying we attack the human outpost in 15 minutes, get up!'" << "\n";
		}
		data["state"] = "main";//change state to main state
		saveToFile(saveFileName, data); //save data
	}

	//main game
	if (data["state"] == "main") {
		std::cout << "Main game not yet made :(" << "\n";
	}

	//else
	else if (data["state"] != "setup" && data["state"] != "tutorial" && data["state"] != "main") { //lets up know if state has a corrupted value
			std::cout << "state is messed up bruh" << "\n";
	}
	return 0;
}
