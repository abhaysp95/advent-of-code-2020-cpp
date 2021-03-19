// cpp file for "day11_util.hpp"

#include "../inc/day11_util.hpp"

#include <iostream>

int deltas[8][2] = {
	{-1, -1}, {-1, 0}, {-1, 1},  // top
	{0, -1}, {0, 1},             // mid
	{1, -1}, {1, 0}, {1, 1}      // bottom
};

size_t check_occupied_seats(std::vector<std::string>& sitting_layout, size_t occupied_seats_threshold) {
	size_t occupied_seats{};
	std::vector<std::string>::iterator current_row = sitting_layout.begin();
	std::vector<std::string>::size_type row_count = sitting_layout.size();
	std::string::size_type col_count = current_row->size();

	while(true) {
		bool layout_not_updated = true;
		std::vector<std::string> temp_sitting_layout{sitting_layout.cbegin(), sitting_layout.cend()};
		for (std::vector<std::string>::size_type current_row_index = 0; current_row_index < row_count; current_row_index++) {
			for (std::string::size_type current_col_index = 0; current_col_index < col_count; current_col_index++) {
				size_t count = count_occupied_seats(current_row_index, current_col_index, temp_sitting_layout);
				if ((count == 0) && (current_row->at(current_col_index) == 'L')) {
					current_row->at(current_col_index) = '#';
				}
				else if ((count >= occupied_seats_threshold) && (current_row->at(current_col_index) == '#')) {
					current_row->at(current_col_index) = 'L';
				}
				// if this doesn't becomes false(even one seat in any row isn't changed) then the whole sitting layout isn't updated
				layout_not_updated &= (temp_sitting_layout[current_row_index][current_col_index] == current_row->at(current_col_index));
			}
			print_seat_matrix(temp_sitting_layout);
			current_row++;
		}
		if (layout_not_updated) {
			// sitting layout isn't updated in this iteration
			break;
		}
	}
	current_row = sitting_layout.begin();
	do {
		std::string::const_iterator current_seat = current_row->cbegin();
		do {
			if (*current_seat == '#') {
				occupied_seats++;
			}
			current_seat++;
		} while (current_seat != current_row->cend());
		current_row++;
	} while (current_row != sitting_layout.cend());
	return occupied_seats;
}

size_t count_occupied_seats(const std::vector<std::string>::size_type row_index, const std::string::size_type col_index,
		const std::vector<std::string>& temp_sitting_layout) {
	size_t count{};
	for (size_t idx = 0; idx < DELTA_SIZE; ++idx) {
		int* delta_pair = deltas[0];
		int row_x = row_index + *(delta_pair);
		int col_x = col_index + *(delta_pair + 1);
		if ((0 <= row_x < temp_sitting_layout.size())
				&& (0 <= col_x < temp_sitting_layout.at(0).size())
				&& (temp_sitting_layout.at(row_index).at(col_index) == '#')) {
			count += 1;
		}
	}
	return count;
}

void print_seat_matrix(const std::vector<std::string>& sitting_layout) {
	std::vector<std::string>::const_iterator sitting_row = sitting_layout.cbegin();
	std::string::const_iterator sitting_column = sitting_row->cbegin();
	do {
		do {
			std::cout << *sitting_column;
			sitting_column++;
		} while (sitting_column != sitting_row->cend());
		std::cout << "\n";
		sitting_row++;
	} while (sitting_row != sitting_layout.cend());
	std::cout << "\n";
}