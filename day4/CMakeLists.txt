set(SOURCES src/main.cpp
	inc/day4_util.hpp
	src/day4_util.cpp)

add_executable(day4 "${SOURCES}")

include_directories(day4 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
