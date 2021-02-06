// cpp file for "day4_util.hpp"

#include "../inc/day4_util.hpp"

#include <algorithm>
#include <cctype>

/** this function first space seperate the blocks and the puts the pair in input_data */
void get_pair_in_input_data(std::map<std::string, std::string>& input_data, const std::string& input_line) {
	std::string::const_iterator first, second;
	first = input_line.begin();
	while (first != input_line.end()) {
		first = std::find_if(first, input_line.end(), [](char c){ return !isspace(c); });
		second = std::find_if(first, input_line.end(), [](char c){ return isspace(c); });
		if (first != input_line.end()) {
			// segfault here
			std::string space_sep_string = std::string(first, second);
			input_data.insert(get_key_value(space_sep_string));
			first = second;
		}
	}
}

std::pair<std::string, std::string> get_key_value(const std::string& pair_block) {
	std::pair<std::string, std::string> input_pair;
	std::string::const_iterator first, second;
	size_t count{};
	first = pair_block.begin();
	// this block should only run two times(as key:value is the input format)
	while (first != pair_block.end()) {
		first = std::find_if(first, pair_block.end(), [](char c){ return !(c == ':'); });
		second = std::find_if(first, pair_block.end(), [](char c){ return c == ':'; });
		if (first != pair_block.end()) {
			if (!count++) {
				//input_pair.first = std::string(first, second);
				input_pair.first.insert(input_pair.first.end(), first, second);
			}
			else {
				//input_pair.second = std::string(first, second);
				input_pair.second.insert(input_pair.second.end(), first, second);
			}
			first = second;
		}
	}
	return input_pair;
}

bool valid_passports(const std::map<std::string, std::string>& input_data) {
	if ((input_data.find("byr") != input_data.end()) &&
			(input_data.find("iyr") != input_data.end()) &&
			(input_data.find("eyr") != input_data.end()) &&
			(input_data.find("hgt") != input_data.end()) &&
			(input_data.find("hcl") != input_data.end()) &&
			(input_data.find("ecl") != input_data.end()) &&
			(input_data.find("pid") != input_data.end())) {
		return true;
	}
	return false;
}