// main file

#include <iostream>
#include <fstream>
#include <vector>

#include "../inc/day11_util.hpp"

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_demo.txt");
	std::vector<std::string> sitting_layout{};
	std::string layout_row{};
	while (std::getline(input_file, layout_row)) {
		sitting_layout.push_back(layout_row);
	}
	size_t occupied_seats = check_occupied_seats(sitting_layout);
	std::cout << "Occupied Seats: " << occupied_seats << std::endl;
	input_file.close();
	return 0;
}