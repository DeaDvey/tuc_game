#include <iostream>
//using namespace std;

int main() {
	//variables//
	std::string species; //define species as null
	bool valid_species = false;
	std::string first_pronoun;
	std::string second_pronoun;
	std::string name;
	int state = 0;
	//variables//

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
