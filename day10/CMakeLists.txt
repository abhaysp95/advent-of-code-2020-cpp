set(SOURCES inc/day10_util.hpp
	src/main.cpp
	src/day10_util.cpp)

add_executable(day10 "${SOURCES}")

include_directories(day10 inc src)

configure_file(input_demo1.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo1.txt")
configure_file(input_demo2.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo2.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
