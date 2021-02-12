// cpp file for "day8_util.hpp"

#include "../inc/day8_util.hpp"

#include <vector>
#include <algorithm>

size_t get_accumulator_value(const std::map<size_t, std::string>& all_operations) {
	size_t accumulator_value{};
	std::map<size_t, std::string>::const_iterator operations_cbegin{all_operations.cbegin()},
		operations_cend{all_operations.cend()};
	std::vector<size_t> index_of_operation_performed{};
	std::pair<std::string, std::string> operation_details{};
	do {
		if (std::find(index_of_operation_performed.cbegin(), index_of_operation_performed.cend(), operations_cbegin->first) !=
				index_of_operation_performed.cend()) {
			// it means operation is already performed and now it'll loop for infintely
			break;
		}
		operation_details = get_operation_detail(operations_cbegin->second);
		if (operation_details.first == "acc") {
			index_of_operation_performed.push_back(operations_cbegin->first);
			perform_arithmetic_operation(operation_details.second, accumulator_value);
		}
		else if (operation_details.first == "jmp") {
			index_of_operation_performed.push_back(operations_cbegin->first);
			move_to_operation(all_operations, operations_cbegin, operation_details.second);
			if (operations_cbegin != all_operations.cbegin()) {
				std::advance(operations_cbegin, -1);  // you still have to perform this one
			}
		}
		else if (operation_details.first == "nop") {
			index_of_operation_performed.push_back(operations_cbegin->first);
		}
		operations_cbegin++;
	} while (operations_cbegin != operations_cend);
	return accumulator_value;
}

/** since details are only space seperated and there's only one space in operation
  * detail no need to do whole string split thing */
std::pair<std::string, std::string> get_operation_detail(const std::string& operation_info) {
	std::pair<std::string, std::string> op_detail;
	size_t pos_of_space = operation_info.find(' ');
	op_detail.first = std::string(operation_info.cbegin(), operation_info.cbegin() + pos_of_space);
	op_detail.second = std::string(operation_info.cbegin() + pos_of_space + 1, operation_info.cend());
	return op_detail;
}

void perform_arithmetic_operation(const std::string& operator_operand, size_t& accumulator_value) {
	char operator_sign = operator_operand.at(0);
	int value = std::stoi(std::string(operator_operand.cbegin() + 1, operator_operand.cend()));
	switch (operator_sign) {
		case '+':
			accumulator_value += value;
			break;
		case '-':
			accumulator_value -= value;
			break;
		default:
			break;
	}
}

void move_to_operation(const std::map<size_t, std::string>& all_operations,
		std::map<size_t, std::string>::const_iterator& all_operations_cpos,
		const std::string& operator_operand) {
	char operator_sign = operator_operand.at(0);
	size_t value = std::stoi(std::string(operator_operand.cbegin() + 1, operator_operand.cend()));
	switch (operator_sign) {
		case '+':
			if (all_operations_cpos != all_operations.cend()) {
				std::advance(all_operations_cpos, value);
			}
			break;
		case '-':
			if (all_operations_cpos != all_operations.cbegin()) {
				std::advance(all_operations_cpos, -value);
			}
			break;
		default:
			break;
	}
}

/** difference between std::advance() and std::prev()/std::next() is that
  * std::advance() changes the actual map iterator you passed, whereas
  * std::prev()/std::next() makes a new copy of iterator*/


/** idea for part2

  loop through the map you had created, if you found that the operation is nop then
  change that to jmp(with same value) and test it out, if it returns with the
  maps iterator reaching to the end of that map, then that's the thing which you had
  to change and now with that changed map, get the value of the accumulator */

size_t get_accumulator_value_part2(std::map<size_t, std::string>& all_operations) {
	size_t accumulator_value{};
	std::map<size_t, std::string>::const_iterator operations_cbegin{all_operations.begin()};
		std::map<size_t, std::string>::const_iterator operations_cend{all_operations.cend()};
	std::pair<std::string, std::string> operation_details{};
	bool is_this_the_correct_change = true;
	bool if_operator_changed = false;
	size_t count{};
	do {
		std::cout << "here and" << "\n";
		if_operator_changed = false;
		operation_details = get_operation_detail(operations_cbegin->second);
		std::map<size_t, std::string> all_new_operations{all_operations.cbegin(), all_operations.cend()};
		std::map<size_t, std::string>::iterator new_operation_begin{all_new_operations.begin()};
		if (operation_details.first == "jmp") {
			std::advance(new_operation_begin, count);
			new_operation_begin->second = change_operation(new_operation_begin->second, "nop");
			if_operator_changed = true;
		}
		else if (operation_details.first == "nop") {
			std::advance(new_operation_begin, count);
			new_operation_begin->second = change_operation(new_operation_begin->second, "jmp");
			if_operator_changed = true;
		}
		if (if_operator_changed) {
			std::cout << "here" << "\n";
			accumulator_value = get_accumulator_value(all_new_operations, is_this_the_correct_change);
			if (is_this_the_correct_change) {
				std::cout << operations_cbegin->first << ", " << operations_cbegin->second << std::endl;
				break;
			}
		}
		operations_cbegin++;
		count++;
	} while (operations_cbegin != operations_cend);
	return accumulator_value;
}

std::string change_operation(const std::string& current_operation, const std::string operation) {
	size_t pos_of_space = current_operation.find(' ');
	std::string operator_operand = std::string(current_operation.cbegin() + pos_of_space + 1, current_operation.cend());
	return std::string(operation + " " + operator_operand);
}

size_t get_accumulator_value(const std::map<size_t, std::string>& all_operations, bool& is_this_the_correct_change) {
	size_t accumulator_value{};
	std::map<size_t, std::string>::const_iterator operations_cbegin{all_operations.cbegin()},
		operations_cend{all_operations.cend()};
	std::vector<size_t> index_of_operation_performed{};
	std::pair<std::string, std::string> operation_details{};
	do {
		if (std::find(index_of_operation_performed.cbegin(), index_of_operation_performed.cend(), operations_cbegin->first) !=
				index_of_operation_performed.cend()) {
			// it means operation is already performed and now it'll loop for infintely
			is_this_the_correct_change = false;
			break;
		}
		operation_details = get_operation_detail(operations_cbegin->second);
		if (operation_details.first == "acc") {
			index_of_operation_performed.push_back(operations_cbegin->first);
			perform_arithmetic_operation(operation_details.second, accumulator_value);
		}
		else if (operation_details.first == "jmp") {
			index_of_operation_performed.push_back(operations_cbegin->first);
			move_to_operation(all_operations, operations_cbegin, operation_details.second);
			if (operations_cbegin != all_operations.cbegin()) {
				std::advance(operations_cbegin, -1);  // you still have to perform this one
			}
		}
		else if (operation_details.first == "nop") {
			index_of_operation_performed.push_back(operations_cbegin->first);
		}
		operations_cbegin++;
	} while (operations_cbegin != operations_cend);
	return accumulator_value;
}