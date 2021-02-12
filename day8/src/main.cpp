// main file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "../inc/day8_util.hpp"

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_demo.txt");
	std::string operation;
	std::map<size_t, std::string> all_operations;
	size_t count{};
	while (std::getline(input_file, operation)) {
		all_operations.insert(std::make_pair(count++, operation));
	}
	input_file.close();

	/************ first part **************
	size_t result = get_accumulator_value(all_operations);
	std::cout << "value just before infinite loop: " << result << std::endl;
	*************************************/

	/************ second part **************/
	size_t result = get_accumulator_value_part2(all_operations);
	std::cout << "value just before infinite loop: " << result << std::endl;
	/**************************************/

	return 0;
}