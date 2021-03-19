// cpp file for "day11_util.hpp"

#include "../inc/day11_util.hpp"

extern int deltas[8][2];

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
		}
		if (layout_not_updated) {
			// sitting layout isn't updated in this iteration
			break;
		}
		// count sitting layout now
	}

	return occupied_seats;
}