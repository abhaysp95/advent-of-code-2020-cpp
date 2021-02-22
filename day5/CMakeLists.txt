set(SOURCES src/main.cpp
	inc/day5_util.hpp
	src/day5_util.cpp)

add_executable(day5 "${SOURCES}")

include_directories(day5 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
