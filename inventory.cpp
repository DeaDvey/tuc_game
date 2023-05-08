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
#include <sstype>
#include <array>
#include <sstream>
#include "header.h"

std::string check_inventory(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {


  return "done";
}

std::string add_to_inventory(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {

  //data key for accessing elements
  std::map<std::string, int> key; //map that stores the above vector
  for (int i = 0; i < data.size(); ++i) {
      key[data[i].first] = i;
  }

  std::istringstream iss(input);
  std::vector<std::string> words{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};
    for (const auto& word : words) {
        std::cout << word << '\n';
    }
    
  
  return "done";
}
