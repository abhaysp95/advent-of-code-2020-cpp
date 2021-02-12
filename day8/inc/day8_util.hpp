// header file

#ifndef _GUARD_DAY8_UTIL_HPP_
#define _GUARD_DAY8_UTIL_HPP_

#include <iostream>
#include <map>
#include <string>

enum operation { acc = 1, jmp = 2, nop = 3 };

size_t get_accumulator_value(const std::map<size_t, std::string>& all_operations);
std::pair<std::string, std::string> get_operation_detail(const std::string& operation_info);
void perform_arithmetic_operation(const std::string& operator_operand, size_t& accumulator_value);
void move_to_operation(const std::map<size_t, std::string>& all_operations,
		std::map<size_t, std::string>::const_iterator& all_operations_cpos,
		const std::string& operator_operand);

size_t get_accumulator_value_part2(std::map<size_t, std::string>& all_operations);
std::string change_operation(const std::string& operations_pos, const std::string operation);
size_t get_accumulator_value(const std::map<size_t, std::string>& all_operations, bool& is_this_the_correct_change);

#endif