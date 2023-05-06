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

std::string talk(std::string& input, std::vector<std::pair<std::string, std::string>>& data) {//function to send a message to the message server
  std::map<std::string, int> key; //map that stores the above vector
    for (int i = 0; i < data.size(); ++i) {
        key[data[i].first] = i;
    }
  std::string final_input = data[key["name"]].second + ":%20";//final input where spaces are replaced by %20
  
  for (int i = 0; i < input.length(); i++) { // loop that replaces spaces with %20
    if (input[i] == ' ') {
            final_input += "%20";
        }
        else {
            final_input += input[i];
        }
  }
  
  std::string script_path = "./talking/talker.sh"; //define bash script, that sends message, path
  std::string command = "bash " + script_path + " " + final_input;
  
  int exit_code = system(command.c_str());

  //if (exit_code == 0) {
  //  std::cout << "Script executed successfully!" << "\n";
  //}
  if (exit_code == 1) {
    std::cout << "Script failed to execute." << "\n";
  }
  
  
  return "done";
}

std::string recieve_chat() {
   std::string command = "bash ./talking/text-finder.sh";
   int exit_code = system(command.c_str());
   
   return "done";
}
