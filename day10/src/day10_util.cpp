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
	// increment extra 1 difference for difference-3
	std::map<size_t, size_t>::iterator get_difference_3 = differences_count->find(3);
	if (get_difference_3 != differences_count->cend()) {
		get_difference_3->second++;
	}
	return differences_count;
}