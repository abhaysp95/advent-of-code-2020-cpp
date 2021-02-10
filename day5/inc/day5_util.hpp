// header file

#ifndef _GUARD_DAY5_UTIL_HPP_
#define _GUARD_DAY5_UTIL_HPP_

#include <iostream>
#include <string>
#include <map>
#include <vector>

size_t get_place(std::string::const_iterator& begin, const std::string::const_iterator& end,
		size_t beg_place, size_t end_place, char first, char second);
std::string get_my_seat_path(const std::map<std::string, size_t>& seats_info, const size_t my_seat_id);
size_t get_my_seat_id(std::vector<size_t>& seat_ids);

#endif