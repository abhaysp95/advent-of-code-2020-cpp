set(SOURCES src/main.cpp
	inc/day9_util.hpp
	src/day9_util.cpp)

add_executable(day9 "${SOURCES}")

include_directories(day9 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
