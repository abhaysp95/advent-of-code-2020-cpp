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

/** question says that my seat isn't in very first and very last, so I think,
  * we can skip first 8 seats and last eigth seats for checking
  */
std::string get_my_seat_path(const std::map<std::string, size_t>& seats_info) {
	// sort the seats
	//std::sort(seats_info.begin(), seats_info.end(),
			//[=](const std::pair<const std::string, size_t>& first, const std::pair<const std::string, size_t>& second) {
					//return first.second < second.second;
				//});
	std::map<std::string, size_t>::const_iterator
		second_from_start{std::next(seats_info.begin(), 8)},
		second_from_end{std::prev(seats_info.end(), 8)};
	// set counter from second seat
	size_t seat_id_counter = second_from_start->second;
	while (second_from_start != second_from_end) {
		if (second_from_start->second != seat_id_counter) {
			// check if +1 and -1 seats exist or not
			if ((std::prev(second_from_start, 1)->second == seat_id_counter - 1) &&
					(std::next(second_from_start, 1)->second == seat_id_counter + 1)) {
				// this is my seat
				return second_from_start->first;
			}
		}
		second_from_start = std::next(second_from_start, 1);
		seat_id_counter++;
	}
	return nullptr;
}