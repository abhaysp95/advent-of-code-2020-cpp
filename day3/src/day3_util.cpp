// cpp file for "day3_util.hpp"

#include "../inc/day3_util.hpp"

size_t count_of_tree_encountered(vec_str& forest, vec_str_iter& forest_iter, str_size& pos_col, size_t trees_met) {
	if (forest_iter == forest.end()) {
		return trees_met;
	}
	if (forest_iter != forest.begin()) {
		if (pos_col + 3 >= forest_iter->size()) {
			duplicate_column(forest_iter, pos_col);
		}
		if (forest_iter->at(pos_col) == '#') {
			forest_iter->at(pos_col) = 'X';
			trees_met++;
		}
		else {
			forest_iter->at(pos_col) = 'O';
		}
	}
	std::cout << *forest_iter << "\n";
	forest_iter++;
	pos_col += 3;
	return count_of_tree_encountered(forest, forest_iter, pos_col, trees_met);
}

void duplicate_column(vec_str_iter& forest_iter, const str_size& pos_col) {
	while (forest_iter->size() <= pos_col + 3) {
		forest_iter->insert(forest_iter->end(), forest_iter->begin(), forest_iter->end());
	}
}