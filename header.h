#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include <string>
#include <vector>

// Declare the addHello function
void saveToFile(const std::string& fileName, const std::vector<std::pair<std::string, std::string>>& data);
void loadFromFile(const std::string& fileName, std::vector<std::pair<std::string, std::string>>& data);
std::string upper(std::string& text);
std::string lower(std::string& text);
std::string readInput(std::string& input, std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName);
std::string tutorial(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName);
std::string game(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName);
std::string map(const std::string& direction, std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName);
std::string character_setup(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName);
std::string travel(const std::string& direction, std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName);
// std::string fatal_error_color = "\033[31m";
// std::string error_color = "\033[33m";
// std::string dialouge_color = "\033[3;32m";
// std::string command_info_color = "\033[34m";
// std::string general_color = "\033[0m";

#endif // MY_FUNCTIONS_H
