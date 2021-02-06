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

bool if_all_required_fields_exist(const std::map<std::string, std::string>& input_data) {
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

/** return true if match found else false */
bool match_value(const std::string& str, const std::regex& reg) {
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg), lastMatch;
	// there will be only one match(if any)
	std::smatch match = *currentMatch;
	// ready() shows that match is found, while empty() will show, not
	if (match.ready()) {
		return true;
	}
	return false;
}

bool if_all_values_are_correct(const std::map<std::string, std::string>& input_data) {
	std::regex reg_byr(R"(^(19[2-9][0-9]|200[0-2])$)");
	std::regex reg_iyr(R"(^(201[0-9]|2020)$)");
	std::regex reg_eyr(R"(^(202[0-9]|2030)$)");
	std::regex reg_hgt(R"(^((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in)$)");
	std::regex reg_hcl(R"(^#[a-fA-F0-9]{6}$)");
	std::regex reg_ecl(R"(^(amb|g(ry|rn)|b(lu|rn)|hzl|oth)$)");
	std::regex reg_pid(R"(^\d{9}$)");
	if (match_value(input_data.find("byr")->second, reg_byr) &&
			match_value(input_data.find("iyr")->second, reg_iyr) &&
			match_value(input_data.find("eyr")->second, reg_eyr) &&
			match_value(input_data.find("hgt")->second, reg_hgt) &&
			match_value(input_data.find("hcl")->second, reg_hcl) &&
			match_value(input_data.find("ecl")->second, reg_ecl) &&
			match_value(input_data.find("pid")->second, reg_pid)) {
		return true;
	}
	return false;
}