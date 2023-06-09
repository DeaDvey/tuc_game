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
#include <array>
#include <sstream>
#include <iterator>
#include "header.h"

//return an array for the inventory when a string is inputed
std::string return_inventory_array(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName) {
  
  std::map<std::string, int> key; //map that stores the above vector
  for (int i = 0; i < data.size(); ++i) {
      key[data[i].first] = i;
  }

  int space_in_inventory = 32;
  std::string inventory = data[key["inventory"]].second;
  std::stringstream ss(inventory);
  std::string word;
  std::string inventory_array[space_in_inventory]; //array that will store the inventory
  int i = 0;
  while (ss >> word && i < space_in_inventory) {
    inventory_array[i] = word;
    i++;
  }
  for (int j = 0; j < i; j++) {
    std::cout << inventory_array[j] << "     ";
    if (j % 3 + 1 == 0) {
      std::cout << "\n";
    }
  }
  return "done";
}

//add item to inventory string
std::string add_to_inventory_array(std::vector<std::pair<std::string, std::string>>& data, const std::string& item) {
  std::map<std::string, int> key; //map that stores the above vector
  for (int i = 0; i < data.size(); ++i) {
      key[data[i].first] = i;
  }
  
  std::string inventory = data[key["inventory"]].second;
  int lenght_of_inv = inventory.length();
  int length_of_item = item.length();
  
  return "done";
}


