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

std::string talk(std::string& input) {//function to send a message to the message server
  std::string final_input;//final input where spaces are replaced by %20
  
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
