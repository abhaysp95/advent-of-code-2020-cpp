// cpp file for "day5_util.hpp"

#include "../inc/day5_util.hpp"

#include <algorithm>

size_t get_place(std::string::const_iterator& begin, const std::string::const_iterator& end,
		size_t beg_place, size_t end_place, char first, char second) {
	size_t mid_place = (beg_place + end_place) / 2;
	if (begin != end) {
		// get the first half
		if (*begin == first) {
			begin++;
			mid_place = get_place(begin, end, beg_place, mid_place, first, second);
		}
		// get the last half
		else if (*begin == second) {
			begin++;
			mid_place = get_place(begin, end, mid_place + 1, end_place, first, second);
		}
	}
	return mid_place;
}

/** question says that my seat isn't in very first and very last, so I think,
  * we can skip first 8 seats and last eigth seats for checking
  */
size_t get_my_seat_id(std::vector<size_t>& seat_ids) {
	std::sort(seat_ids.begin(), seat_ids.end(), [=](size_t first, size_t second) { return first < second; });
	std::vector<size_t>::const_iterator begin_from{seat_ids.begin() + 8}, end_is{seat_ids.end() - 8};
	std::vector<size_t>::const_iterator prev_seat = begin_from - 1;
	while (begin_from != end_is) {
		/**
		  * if current_seat isn't just the increment of prev_seat then
		  * if value of prev_seat + 1 is equals to value of current seat and
		  * if value of current_seat + 1 is equals to value of next seat, then
		  * current seat is my seat
		  */
		if ((*prev_seat + 1) != *begin_from) {
			// check if next seat from my seat for my seat exist or not
			if ((*prev_seat + 2) == *begin_from) {
				return *begin_from - 1;
			}
		}
		prev_seat = begin_from;
		begin_from++;
	}
	return 0;
}


/** this function is not doing anything yet, an idea is to find the seat_id just
  * like in the above function but return the path, for that we have to create path
  * from the previous existing path + 1, which could be next seat or first seat in
  * next row
  */

/** question says that my seat isn't in very first and very last, so I think,
  * we can skip first 8 seats and last eigth seats for checking
  */
std::string get_my_seat_path(const std::map<std::string, size_t>& seats_info, size_t my_seat_id) {
	/** use the get_my_seat_id() function to get the seat id, now as per
	 * question one seat before and after my seat do exist
	 */
	std::string my_seat_path;
	// get one previous seat path from your seat id
	std::map<std::string, size_t>::const_iterator prev_seat_info = std::find_if(seats_info.begin(), seats_info.end(),
			[my_seat_id](const std::pair<const std::string, size_t>& pair) {
				return pair.second == my_seat_id - 1;
			});
	/* now get the the next seat path from the prev_seat_info. Now, my seat
	 * could either be just next to prev seat or the first seat in next row
	 */
	my_seat_path = std::string(prev_seat_info->first.begin(), prev_seat_info->first.end());
	std::string::const_reverse_iterator prev_seat_criter_begin = prev_seat_info->first.rbegin();
	std::string::const_reverse_iterator prev_seat_criter_end = prev_seat_info->first.rend();
	std::string::reverse_iterator my_seat_riter_begin = my_seat_path.rbegin();
	size_t r_count{};  /** if all three columns are R then my seat is first in next row */
	while (prev_seat_criter_begin != prev_seat_criter_end) {
		if (*prev_seat_criter_begin == 'R') {
			*my_seat_riter_begin = 'L';
			r_count++;
		}
		else if (*prev_seat_criter_begin == 'L') {
			*my_seat_riter_begin = 'R';
			// cause if you'll get R then there's space just next to this seat
			break;
		}
		else {
			// now my seat is the first seat in the next row
			if (r_count == 3) {
				if (*prev_seat_criter_begin == 'B') {
					*my_seat_riter_begin = 'F';
				}
				else if (*prev_seat_criter_begin == 'F') {
					*my_seat_riter_begin = 'B';
					break;
				}
			}
		}
		prev_seat_criter_begin++;
		my_seat_riter_begin++;
	}
	/** now just to double check if id from my_seat_path is equal to +1 of prev_seat_id */
	std::string::const_iterator my_seat_path_cbegin{my_seat_path.begin()}, my_seat_path_cend{my_seat_path.end()};
	size_t get_row_pos = get_place(my_seat_path_cbegin, my_seat_path_cend, 0, 127, 'F', 'B');
	size_t get_col_pos = get_place(my_seat_path_cbegin, my_seat_path_cend, 0, 7, 'L', 'R');
	size_t temp_my_seat_id = get_row_pos * 8 + get_col_pos;
	if (temp_my_seat_id == my_seat_id) {
		return my_seat_path;
	}
	return nullptr;
}