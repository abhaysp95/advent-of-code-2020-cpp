set(SOURCES src/main.cpp
	inc/day8_util.hpp
	src/day8_util.cpp)

add_executable(day8 "${SOURCES}")

include_directories(day8 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
