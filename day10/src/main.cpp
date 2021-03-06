// main file

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "../inc/day10_util.hpp"

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	size_t rating{};
	std::vector<size_t> your_adapters_joltage_ratings{};
	your_adapters_joltage_ratings.push_back(0);
	while(input_file >> rating) {
		your_adapters_joltage_ratings.push_back(rating);
	}
	input_file.close();
	your_adapters_joltage_ratings.push_back(
			*(std::max_element(your_adapters_joltage_ratings.cbegin(),
					your_adapters_joltage_ratings.cend())) + 3);

	/************ answer for first part ***************/
	long first_part_result = get_final_difference_between_1_and_3_jolts(your_adapters_joltage_ratings);
	std::cout << "\nDifference is: " << first_part_result << std::endl;
	/**************************************************/

	/************ answer for second part ***************/
	unsigned long second_part_result = total_arrangement_of_adapters(your_adapters_joltage_ratings);
	std::cout << "\nTotal arrangements count is: " << second_part_result << std::endl;
	return 0;
}