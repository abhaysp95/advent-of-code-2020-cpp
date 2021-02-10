// cpp file for "day6_util.hpp"

#include "../inc/day6_util.hpp"

#include <set>
#include <map>

size_t sum_of_total_questions(const std::vector<std::vector<std::string>>& total_input) {
	size_t result{};
	for (const std::vector<std::string>& group_input: total_input) {

		/***************** first part *******************
		result += get_group_distinct_question_count(group_input);
		************************************************/

		/**************** second part ******************/
		result += get_question_count_which_everyone_answered_yes_in_group(group_input);
		/***********************************************/
	}
	return result;
}

size_t get_group_distinct_question_count(const std::vector<std::string>& group_input) {
	std::set<char> questions;
	for (const std::string& questions_attempted_by_one_user: group_input) {
		for (const char& question: questions_attempted_by_one_user) {
			questions.insert(question);
		}
	}
	return questions.size();
}

size_t get_question_count_which_everyone_answered_yes_in_group(const std::vector<std::string>& group_input) {
	std::set<char> questions;
	std::map<char, size_t> question_count;
	std::map<char, size_t>::iterator question_pos;
	for (const std::string& questions_attempted_by_one_user: group_input) {
		for (const char& question: questions_attempted_by_one_user) {
			/** first check if question has been inserted in map or not */
			question_pos = question_count.find(question);
			if (question_pos == question_count.end()) {
				/** question not found */
				question_count.insert(std::make_pair(question, 1));
			}
			else {
				question_pos->second += 1; // if question already there, increase count
			}
		}
	}
	size_t count{}, size_of_group{group_input.size()};
	for (const std::pair<const char, size_t>& question_with_count: question_count) {
		if (question_with_count.second >= size_of_group) {
			count++;
		}
	}
	return count;
}