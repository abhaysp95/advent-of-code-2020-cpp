// main file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "../inc/day5_util.hpp"

/** part1 of the question */
void part1() {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	std::string pos_str;
	std::vector<size_t> get_seat_ids;
	while (input_file >> pos_str) {
		std::string pos_row(pos_str.begin(), (pos_str.begin() + 7));
		std::string pos_col(pos_str.begin() + 7, pos_str.end());
		std::string::const_iterator pos_row_begin{pos_row.begin()}, pos_row_end{pos_row.end()};
		std::string::const_iterator pos_col_begin{pos_col.begin()}, pos_col_end{pos_col.end()};
		size_t get_row_pos = get_place(pos_row_begin, pos_row_end, 0, 127, 'F', 'B');
		size_t get_col_pos = get_place(pos_col_begin, pos_col_end, 0, 7, 'L', 'R');
		std::cout << "row: " << get_row_pos << ", col: " << get_col_pos << "\n";
		get_seat_ids.push_back(get_row_pos * 8 + get_col_pos);
	}
	std::vector<size_t>::const_iterator highest_seat_id = std::max_element(get_seat_ids.begin(), get_seat_ids.end());
	std::cout << "\nhighest seat id: " << *highest_seat_id << std::endl;
	input_file.close();
}

int main(int argc, char **argv) {
	part1();
	return 0;
}