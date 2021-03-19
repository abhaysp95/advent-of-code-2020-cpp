set(SOURCES inc/day11_util.hpp
	src/main.cpp
	src/day11_util.cpp)

add_executable(day11 ${SOURCES})

include_directories(day11 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
