// main file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../inc/day6_util.hpp"

void print(const std::vector<std::vector<std::string>>& total_input) {
	for (const std::vector<std::string>& input_from_group: total_input) {
		for (const std::string& input_from_user: input_from_group) {
			std::cout << input_from_user << "\n";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	std::string input_from_user;
	std::vector<std::string> input_from_group;
	std::vector<std::vector<std::string>> total_input;
	while (std::getline(input_file, input_from_user)) {
		if (input_from_user.empty()) {
			/** take the group as input */
			total_input.push_back(input_from_group);
			input_from_group.clear();
		}
		/** else block is necessary as it'll also try to push_back blank line too */
		else {
			input_from_group.push_back(input_from_user);
		}
	}
	total_input.push_back(input_from_group);  // take last group input
	input_from_group.clear();
	input_file.close();
	print(total_input);

	/***************** first part *******************
	size_t total_attempted_questions = sum_of_total_questions(total_input);
	std::cout << "sum of total questions attempted: " << total_attempted_questions << std::endl;
	************************************************/

	/**************** second part ******************/
	size_t questions_answered_yes_count = sum_of_total_questions(total_input);
	std::cout << "sum of questions which everyone answered yes in group: " << questions_answered_yes_count << std::endl;
	/************************************************/

return 0;
}