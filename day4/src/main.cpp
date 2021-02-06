// main file

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "../inc/day4_util.hpp"

void print(const std::map<std::string, std::string>& input_data);
bool check_if_passport_is_valid(const std::map<std::string, std::string>& input_data, size_t& valid_passports_count);

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	std::string temp_line;
	std::map<std::string, std::string> input_data;
	size_t valid_passports_count{};
	while (getline(input_file, temp_line)) {
		// empty line is blank space
		if (temp_line.empty()) {
			// print the data, first so that I know it's working correctly
			if (check_if_passport_is_valid(input_data, valid_passports_count)) {
				print(input_data);
				std::cout << "\n";
			}
			input_data.clear();
			continue;
		}
		get_pair_in_input_data(input_data, temp_line);
	}
	/** last passport is yet to be checked */
	if (!input_data.empty()) {
		if (check_if_passport_is_valid(input_data, valid_passports_count)) {
			print(input_data);
		}
		input_data.clear();
	}
	input_file.close();
	std::cout << "\nValid passports are: " << valid_passports_count;
	std::cout << std::endl;
	return 0;
}

void print(const std::map<std::string, std::string>& input_data) {
	// warning here, for reference of pair
	// std::map's iterator returns std::pair<const key_type, T>, so either use
	// non-reference std::pair or use with the type std::map returns
	for (const std::pair<const std::string, std::string>& pair: input_data) {
		std::cout << pair.first << ", " << pair.second << "\n";
	}
}

bool check_if_passport_is_valid(const std::map<std::string, std::string>& input_data,
		size_t& valid_passports_count) {
	if (valid_passports(input_data)) {
		valid_passports_count++;
		return true;
	}
	return false;
}