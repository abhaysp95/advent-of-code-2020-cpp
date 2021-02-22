// cpp file for "day9_util.hpp"

#include "../inc/day9_util.hpp"

#include <algorithm>
#include <numeric>

size_t first_defaulter_number(std::vector<size_t> xmas_data, const size_t preamble_size) {
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

size_t get_encryption_weakness_number(const std::vector<size_t>& xmas_data) {
	size_t defaulter = first_defaulter_number(xmas_data, 25);
	std::cout << "defaulter is: " << defaulter << "\n";
	size_t enc_weakness{};
	std::vector<size_t>::size_type initial{2};
	bool got_correct_list = false;
	while (initial <= xmas_data.size()) {
		std::vector<size_t>::const_iterator start_from{xmas_data.cbegin()}, end_to{xmas_data.cend()};
		do {
			std::vector<size_t> temp_list_to_check_weakness{start_from, start_from + initial};
			got_correct_list = is_this_correct_list(temp_list_to_check_weakness, defaulter);
			if (got_correct_list) {
				enc_weakness += sum_max_min(temp_list_to_check_weakness);
			}
			start_from++;
		} while (start_from + (initial - 1) != end_to);
		initial++;
	}
	return enc_weakness;
}

bool is_this_correct_list(const std::vector<size_t>& temp_list, const size_t defaulter) {
	size_t temp_sum{};
	temp_sum = std::accumulate(temp_list.cbegin(), temp_list.cend(), temp_sum);
	if (temp_sum == defaulter) {
		return true;
	}
	return false;
}

size_t sum_max_min(const std::vector<size_t>& temp_list) {
	std::vector<size_t>::const_iterator max = std::max_element(temp_list.cbegin(), temp_list.cend());
	std::vector<size_t>::const_iterator min = std::min_element(temp_list.cbegin(), temp_list.cend());
	return *max + *min;
}

//size_t sum_max_min(const std::vector<size_t>& temp_list) {
	//size_t max{temp_list.at(0)}, min{temp_list.at(0)};
	//for (std::vector<size_t>::size_type i = 0; i < temp_list.size(); ++i) {
		//if (max < temp_list.at(i)) {
			//max = temp_list.at(i);
		//}
		//if (min > temp_list.at(i)) {
			//min = temp_list.at(i);
		//}
	//}
	//return max + min;
//}