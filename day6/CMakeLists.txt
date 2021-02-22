set(SOURCES src/main.cpp
	inc/day6_util.hpp
	src/day6_util.cpp)

add_executable(day6 "${SOURCES}")

include_directories(day6 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
