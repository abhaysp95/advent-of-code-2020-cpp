// header file

#ifndef _GUARD_DAY4_UTIL_HPP_
#define _GUARD_DAY4_UTIL_HPP_

#include <string>
#include <map>

void get_pair_in_input_data(std::map<std::string, std::string>& input_data, const std::string& input_line);
std::pair<std::string, std::string> get_key_value(const std::string& pair_block);
bool valid_passports(const std::map<std::string, std::string>& input_data);

#endif