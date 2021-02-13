// header file

#ifndef _GUARD_DAY9_UTIL_HPP_
#define _GUARD_DAY9_UTIL_HPP_

#include <iostream>
#include <vector>

size_t first_defaulter_number(std::vector<size_t> xmas_data, const size_t preamble_size);
bool check_if_number_is_correct(const std::vector<size_t>& check_within_numbers, const size_t& number_to_check);
size_t get_encryption_weakness_number(const std::vector<size_t>& xmas_data);
bool is_this_correct_list(const std::vector<size_t>& temp_list, const size_t defaulter);
size_t sum_max_min(const std::vector<size_t>& temp_list);

#endif