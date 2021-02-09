// cpp file for "day5_util.hpp"

#include "../inc/day5_util.hpp"

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