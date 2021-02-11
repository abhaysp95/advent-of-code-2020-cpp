// header file

#ifndef _GUARD_DAY7_UTIL_HPP_
#define _GUARD_DAY7_UTIL_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <map>

size_t get_bag_counts(const std::vector<std::string>& all_bags_info, const std::string color_name);
std::string::const_iterator get_color_position(const std::string& bag_info, const std::string color_name);
std::string get_secondary_color_name(const std::string& bag_info);
size_t get_bag_contain_count(const std::vector<std::string>& all_bags_info, const std::string color_name);
std::map<std::string, size_t> get_bag_details(const std::string& bag_info);

#endif