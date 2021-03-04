// cpp file for "day10_util.hpp"

#include "../inc/day10_util.hpp"

#include <iostream>
#include <algorithm>

const long get_final_difference_between_1_and_3_jolts(std::vector<size_t>& input_joltage_ratings) {
	// sort the input_joltage_ratings first
	std::sort(input_joltage_ratings.begin(), input_joltage_ratings.end());
	const std::map<size_t, size_t>* const jolt_difference_map = get_all_jolt_differences(input_joltage_ratings);
	std::map<size_t, size_t>::const_iterator get_1_jolt_difference = jolt_difference_map->find(1);
	std::map<size_t, size_t>::const_iterator get_3_jolt_difference = jolt_difference_map->find(3);
	return get_1_jolt_difference->second * get_3_jolt_difference->second;
}

const std::map<size_t, size_t>* const get_all_jolt_differences(const std::vector<size_t>& input_joltage_ratings) {
	std::map<size_t, size_t>* differences_count = new std::map<size_t, size_t>();
	std::vector<size_t>::const_iterator my_device_joltage_rating = std::max_element(input_joltage_ratings.cbegin(), input_joltage_ratings.cend());
	std::vector<size_t>::const_iterator get_joltage_ratings{input_joltage_ratings.cbegin()};
	size_t current_joltage_rating{};
	do {
		if ((current_joltage_rating + 1 == *get_joltage_ratings)
				|| (current_joltage_rating + 2 == *get_joltage_ratings)
				|| (current_joltage_rating + 3 == *get_joltage_ratings)) {
			size_t get_difference = *get_joltage_ratings - current_joltage_rating;
			std::cout << "Current rating: (" << current_joltage_rating
				<< "), next applied rating: (" << *get_joltage_ratings
				<< "), difference: " << get_difference << "\n";
			std::map<size_t, size_t>::iterator pos_of_joltage_rating = differences_count->find(get_difference);
			if (pos_of_joltage_rating != differences_count->cend()) {
				pos_of_joltage_rating->second++;
			}
			else {
				differences_count->insert(std::make_pair(get_difference, 1));
			}
			current_joltage_rating += get_difference;
		}
		get_joltage_ratings++;
	} while ((get_joltage_ratings != input_joltage_ratings.cend())
			&& (current_joltage_rating <= *my_device_joltage_rating + 3));
	return differences_count;
}


/** second part is kinda solved like this

  get the sorted joltage ratings
  t -> total_arrangements
  m -> multiplier_count
  o -> count_one

0. t - 1, m - 1, o - 1
1. m - 1, o - 1
4. t - 1, m - 1, o - 1
5. m - 1, o - 1
6. m - 2, o - 2
7. m - 4, o - 3
10. t - 4, m - 1, o - 1
11. m - 1, o - 1
12. m - 2, o - 2
15. t - 8, m - 1
16. m - 1, o - 1
19. t - 8, m - 1, o - 1
22. t - 8, m - 1, o - 1

  */

const unsigned long total_arrangement_of_adapters(const std::vector<size_t>& input_joltage_ratings) {
	unsigned long total_arrangements{1};
	size_t count_one{};
	size_t multiplier_count{1};
	std::vector<size_t>::const_iterator current_joltage{input_joltage_ratings.cbegin()};
	while (current_joltage != input_joltage_ratings.cend()) {
		if (*(current_joltage + 1) - *current_joltage == 1) {
			multiplier_count += count_one;
			count_one++;
		}
		else if (*(current_joltage + 1) - *current_joltage == 3) {
			total_arrangements *= multiplier_count;
			multiplier_count = 1;
			count_one = 0;
		}
		current_joltage++;
	}
	return total_arrangements;
}