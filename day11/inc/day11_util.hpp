// header file

#ifndef _GUARD_DAY11_UTIL_HPP_
#define _GUARD_DAY11_UTIL_HPP_

#include <vector>
#include <string>
#include <array>

	/**
	  deltas for seat checking
	  (-1, -1) -> for top-left corner
	  (-1, 0 ) -> for top-mid corner
	  (-1, 1 ) -> for top-right corner
	  (0 , -1) -> for mid-left corner
	  (0 , 1 ) -> for mid-right corner
	  (1 , -1) -> for bottom-left corner
	  (1 , 0 ) -> for bottom-mid corner
	  (1 , 1 ) -> for bottom-right corner
	*/

//std::array<std::array<int, 2>, 8> deltas = {  // problem(excess elements in struct initializer)
int deltas[8][2] = {
	{-1, -1}, {-1, 0}, {-1, 1},  // top
	{0, -1}, {0, 1},             // mid
	{1, -1}, {1, 0}, {1, 1}      // bottom
};

size_t check_occupied_seats(std::vector<std::string>& sitting_layout, size_t occupied_seats_threshold = 4);
size_t count_occupied_seats(const std::vector<std::string>::size_type row_index, const std::string::size_type col_index, const std::vector<std::string>& temp_sitting_layout);

#endif