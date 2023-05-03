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
std::string display_map(std::vector<std::pair<std::string, std::string>>& data, const std::string& saveFileName);
std::string map_defenitions(std::string map[100][84]);
std::string map_descriptions(std::string map[100][84]);

#endif // MY_FUNCTIONS_H
