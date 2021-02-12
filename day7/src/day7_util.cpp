// cpp file for "day7_util.hpp"

#include "../inc/day7_util.hpp"

#include <set>
#include <algorithm>
#include <cctype>
#include <stdexcept>

/** NOTE:
 * Use map(hashmap) for this questions solution as it would optimize the
 * program very much I haven't used it, cause I didn't thought of it at that
 * time. You have to have a map, in which key will be the color mentioned at the
 * begining of the line and value will be another map(say sub-map) which will
 * contain the color-name and color count which main color contains, that way
 * you don't have to do this much looping(which I have done) in program and no
 * splitting several times
*/

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

size_t get_bag_contain_count(const std::vector<std::string>& all_bags_info, const std::string color_name) {
	static size_t bag_capacity{};  // prev_bag_capacity was here
	size_t temp_count{};
	std::map<std::string, size_t> color_map;
	std::vector<std::string>::const_iterator bags_info_cbegin{all_bags_info.cbegin()}, bags_info_cend{all_bags_info.cend()};
	bool found_main_color = false;
	do {
		// find where we can find that color bag info
		std::string::const_iterator get_main_color_pos_citer = get_color_position(*bags_info_cbegin, color_name);
		if (get_main_color_pos_citer == bags_info_cbegin->begin()) {
			// this is the color bag for which we should look what type of bags it can hold
			found_main_color = true;
			color_map = get_bag_details(*bags_info_cbegin);
			if (!color_map.empty()) {
				std::map<std::string, size_t>::const_iterator map_elements_cbegin{color_map.cbegin()},
					map_elements_cend{color_map.end()};
				do {
					size_t count{map_elements_cbegin->second};
					/** tried to not use this extra loop(you can see the commented block at the very end) */
					while (count != 0) {
						size_t return_count = get_bag_contain_count(all_bags_info, map_elements_cbegin->first);
						bag_capacity += return_count;
						count--;
					}
					/** extra loop ends here */
					map_elements_cbegin++;
				} while (map_elements_cbegin != map_elements_cend);
			}
			temp_count += 1;
			if (!color_map.empty()) {
				//bag_capacity += 1;
			}
		}
		if (found_main_color) { break; }
		bags_info_cbegin++;
	} while (bags_info_cbegin != bags_info_cend);
	// return the main count for my bag
	if (color_name == "shiny gold") {
		return bag_capacity;
	}
	return temp_count;
}

std::map<std::string, size_t> get_bag_details(const std::string& bag_info) {
	std::map<std::string, size_t> map_for_color_count;
	std::vector<size_t> color_counts;
	std::vector<std::string> color_names;
	std::string color_name{};
	bool number_found = false;
	std::string::const_iterator first{bag_info.cbegin()}, second{}, bag_info_cend{bag_info.cend()};
	do {
		first = std::find_if(first, bag_info_cend, [=](const char& c){ return !isspace(c); });
		second = std::find_if(first, bag_info_cend, [=](const char& c){ return isspace(c); });
		if (first != bag_info_cend) {
			std::string temp_str{first, second};
			if (number_found) {
				// it means atleast one count is found, which means we should start
				// checking for color names now
				if ((temp_str == "bag,") ||
						(temp_str == "bag.") ||
						(temp_str == "bags,") ||
						(temp_str == "bags.")) {
					color_names.push_back(std::string(color_name.begin(), color_name.end() - 1));
					color_name.clear();
					number_found = false;
				}
				else {
					color_name += temp_str + " ";
				}
				first = second;
				continue;
			}
			try {
				if (stoi(temp_str)) {
					number_found = true;
					color_counts.push_back(stoi(temp_str));
				}
			} catch (std::invalid_argument) {
				// do nothing
			}
			first = second;
		}
	} while (first != bag_info_cend);
	// they should be equal
	if ((!color_counts.empty()) && (color_names.size() == color_counts.size())) {
		std::vector<size_t>::size_type i{};
		for (i = 0; i < color_counts.size(); ++i) {
			map_for_color_count.insert(std::make_pair(color_names[i], color_counts[i]));
		}
	}
	return map_for_color_count;
}




	/*do {
		size_t count{map_elements_cbegin->second};
		size_t return_count = get_bag_contain_count(all_bags_info, map_elements_cbegin->first);
		//prev_bag_capacity = bag_capacity;
		prev_bag_capacity += (return_count * count);
		map_elements_cbegin++;
	} while (map_elements_cbegin != map_elements_cend);
	//bag_capacity += 1;
}
if (!color_map.empty()) {
	// logic not correct
	bag_capacity += prev_bag_capacity;
	//temp_count += bag_capacity - prev_bag_capacity;  // answer 31, now
	temp_count = prev_bag_capacity;
	prev_bag_capacity = 0;
}
else {
	temp_count += 1;  // do something like new bag_capacity - prev bag_capacity
}
//bag_capacity += 1;  // check it later*/
