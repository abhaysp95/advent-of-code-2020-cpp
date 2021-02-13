// main file

#include <iostream>
#include <fstream>
#include <vector>

#include "../inc/day9_util.hpp"

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	std::vector<size_t> xmas_data;
	size_t number;
	while (input_file >> number) {
		xmas_data.push_back(number);
	}
	input_file.close();

	/************* first part ******************
	size_t defaulter_number = first_defaulter_number(xmas_data, 25);
	std::cout << "Defaulter number is: " << defaulter_number << std::endl;
	*******************************************/

	/************* first part *****************/
	size_t encryption_weakness = get_encryption_weakness_number(xmas_data);
	std::cout << "Encryption weakness number is: " << encryption_weakness << std::endl;
	/******************************************/
	return 0;
}

/** full form of XMAS is 'eXchange-Masking Addition System' */