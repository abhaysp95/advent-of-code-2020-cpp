set(SOURCES src/main.cpp
	inc/day3_util.hpp
	src/day3_util.cpp)

add_executable(day3 "${SOURCES}")

include_directories(day3 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
