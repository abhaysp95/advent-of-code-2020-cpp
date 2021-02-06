// header file

#ifndef _GUARD_DAY4_UTIL_HPP_
#define _GUARD_DAY4_UTIL_HPP_

#include <string>
#include <map>
#include <regex>

void get_pair_in_input_data(std::map<std::string, std::string>& input_data, const std::string& input_line);
std::pair<std::string, std::string> get_key_value(const std::string& pair_block);
bool if_all_required_fields_exist(const std::map<std::string, std::string>& input_data);
bool match_value(const std::string& str, const std::regex& reg);
bool if_all_values_are_correct(const std::map<std::string, std::string>& input_data);

#endif