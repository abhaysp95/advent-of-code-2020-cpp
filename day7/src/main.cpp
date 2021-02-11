// main file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../inc/day7_util.hpp"

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	std::string bag_info;
	std::vector<std::string> all_bags_info;
	while (std::getline(input_file, bag_info)) {
		all_bags_info.push_back(bag_info);
	}
	input_file.close();

	/************** first part *****************
	size_t color_counts = get_bag_counts(all_bags_info, "shiny gold");
	std::cout << "bag colors containing atleast one shiny gold bag: " << color_counts << std::endl;
	*******************************************/

	/************** second part ****************/
	size_t number_of_bags_contained = get_bag_contain_count(all_bags_info, "shiny gold");
	std::cout << "count of bags contained by my bag(shiny gold): " << number_of_bags_contained << std::endl;
	/*******************************************/
	return 0;
}