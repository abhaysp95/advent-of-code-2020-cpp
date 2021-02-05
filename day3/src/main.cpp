// main file

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../inc/day3_util.hpp"

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	std::string tree_row;
	std::vector<std::string> forest;
	while (getline(input_file, tree_row)) {
		forest.push_back(tree_row);
	}
	str_size pos_col{};
	vec_str_iter forest_iter = forest.begin();
	size_t number_of_trees_encountered = count_of_tree_encountered(forest, forest_iter, pos_col, 0);
	std::cout << "Number of trees encountered: " << number_of_trees_encountered << std::endl;
	return 0;
}