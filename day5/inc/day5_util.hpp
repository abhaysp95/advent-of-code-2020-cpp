// header file

#ifndef _GUARD_DAY5_UTIL_HPP_
#define _GUARD_DAY5_UTIL_HPP_

#include <iostream>
#include <string>

size_t get_place(std::string::const_iterator& begin, const std::string::const_iterator& end,
		size_t beg_place, size_t end_place, char first, char second);

#endif