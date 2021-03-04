// main file

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "../inc/day10_util.hpp"

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	size_t rating{};
	std::vector<size_t> your_adapters_joltage_ratings{};
	while(input_file >> rating) {
		your_adapters_joltage_ratings.push_back(rating);
	}

	/************ answer for first part ***************/
	long first_part_result = get_final_difference_between_1_and_3_jolts(your_adapters_joltage_ratings);
	std::cout << "\nDifference is: " << first_part_result << std::endl;
	/**************************************************/
	return 0;
}