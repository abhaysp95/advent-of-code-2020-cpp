cmake_minimum_required(VERSION 3.15)
project(Advent_Of_Code_2020_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# trying to put compile_commands.json to root folder
# add_custom_target(
	#copy-compile-commands ALL
	#${CMAKE_COMMAND} -E copy_if_different
	#${CMAKE_BINARY_DIR}/compile_commands.json
	#${CMAKE_CURRENT_LIST_DIR}
	#)

add_subdirectory(day1)
add_subdirectory(day2)
add_subdirectory(day3)
add_subdirectory(day4)
add_subdirectory(day5)
add_subdirectory(day6)
add_subdirectory(day7)
add_subdirectory(day8)
add_subdirectory(day9)
