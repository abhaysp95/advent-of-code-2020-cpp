// cpp file for "day7_util.hpp"

#include "../inc/day7_util.hpp"

#include <set>
#include <algorithm>
#include <cctype>

size_t get_bag_counts(const std::vector<std::string>& all_bags_info, const std::string color_name) {
	static std::set<std::string> bags_color;
	std::vector<std::string>::const_iterator bags_info_cbegin{all_bags_info.cbegin()}, bags_info_cend{all_bags_info.cend()};
	do {
		std::string::const_iterator color_pos_primary = get_color_position(*bags_info_cbegin, color_name);
		if (color_pos_primary == bags_info_cbegin->cend()) {
			bags_info_cbegin++;
			continue;
		}
		if ((color_pos_primary != bags_info_cbegin->begin()) &&
				(color_pos_primary != bags_info_cend->end())) {
			/** this means that you found the color in the sentence and it's not
			  * int the begining of the sentence which means now you have to the
			  * color of the bag which can contain this color bag
			  */
			std::string secondary_color = get_secondary_color_name(*bags_info_cbegin);
			bags_color.insert(secondary_color);  // this secondary_color bag contains the color_name bag
			get_bag_counts(all_bags_info, secondary_color);
		}
		bags_info_cbegin++;
	} while (bags_info_cbegin != bags_info_cend);
	return bags_color.size();
}

std::string::const_iterator get_color_position(const std::string& bag_info, const std::string color_name) {
	std::string::const_iterator bag_info_cbegin{bag_info.cbegin()}, bag_info_cend{bag_info.cend()};
	std::string::const_iterator prev_position = bag_info_cbegin;
	do {
		bag_info_cbegin = std::find(bag_info_cbegin, bag_info_cend, color_name[0]);
		if (bag_info_cbegin != bag_info_cend) {
			/** it means that character has matched now check if rest of the string matches or not */
			prev_position = bag_info_cbegin;
			size_t color_str_len = color_name.size() - 1;  // already checked for first position
			size_t count{1};
			bool color_found = true;
			while (count <= color_str_len) {
				if (*(bag_info_cbegin + 1) == color_name[count]) {
					// next char matched
					bag_info_cbegin++;
					count++;
				}
				else {
					color_found = false;  // not what we are looking for
					break;
				}
			}
			// if color found break out of outer loop too
			if (color_found) {
				break;
			}
			bag_info_cbegin++;
		}
		if (bag_info_cbegin == bag_info_cend) {
			prev_position = bag_info_cbegin;
		}
	} while(bag_info_cbegin != bag_info_cend);
	return prev_position;
}

std::string get_secondary_color_name(const std::string& bag_info) {
	std::string secondary_color_name{};
	std::string::const_iterator first{bag_info.cbegin()}, second{};
	while (first != bag_info.cend()) {
		first = std::find_if(first, bag_info.cend(), [=](const char& c){ return !isspace(c); });
		second = std::find_if(first, bag_info.cend(), [=](const char& c){ return isspace(c); });
		if (first != bag_info.cend()) {
			std::string temp_str = std::string(first, second);
			if (temp_str == "bags") {
				secondary_color_name = std::string(secondary_color_name.begin(), secondary_color_name.end() - 1);
				break;
			}
			secondary_color_name += temp_str + " ";
			first = second;
		}
	}
	return secondary_color_name;
}