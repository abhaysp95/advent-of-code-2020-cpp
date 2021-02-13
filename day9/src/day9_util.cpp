// cpp file for "day9_util.hpp"

#include "../inc/day9_util.hpp"

size_t first_defaulter_number(std::vector<size_t>& xmas_data, const size_t preamble_size) {
	size_t defaulter{};
	std::vector<size_t>::const_iterator number_to_check_citer{xmas_data.cbegin() + preamble_size};
	std::vector<size_t>::const_iterator data_begin{xmas_data.cbegin()}, data_end{xmas_data.cend()};
	bool is_number_not_found = true;
	do {
		is_number_not_found = true;
		std::vector<size_t> check_within_numbers{data_begin, data_begin + preamble_size};
		// delete one from start
		is_number_not_found = check_if_number_is_correct(check_within_numbers, *number_to_check_citer);
		if (!is_number_not_found) {
			return *number_to_check_citer;
		}
		data_begin = xmas_data.erase(data_begin); // erase() will return next valid iterator
		//number_to_check_citer++;
		// no need, cause erase() is already making increase number_to_check_citer by one step
	} while (number_to_check_citer != data_end);
	return defaulter;
}

bool check_if_number_is_correct(const std::vector<size_t>& check_within_numbers, const size_t& number_to_check) {
	bool is_this_correct_number = false;
	std::vector<size_t>::const_iterator first{}, second{};
	for (first = check_within_numbers.begin(); first != check_within_numbers.end() - 1; ++first) {
		for (second = first + 1; second != check_within_numbers.end(); ++second) {
			// just in case
			if (*first != *second) {
				if (*first + *second == number_to_check) {
					return true;
				}
			}
		}
	}
	return is_this_correct_number;
}