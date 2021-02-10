// header file

#ifndef _GUARD_DAY6_UTIL_HPP_
#define _GUARD_DAY6_UTIL_HPP_

#include <iostream>
#include <vector>
#include <string>

size_t sum_of_total_questions(const std::vector<std::vector<std::string>>& total_input);

size_t get_group_distinct_question_count(const std::vector<std::string>& group_input);

size_t get_question_count_which_everyone_answered_yes_in_group(const std::vector<std::string>& group_input);

#endif