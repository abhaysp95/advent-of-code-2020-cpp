set(SOURCES src/main.cpp
	inc/day2_util.hpp
	src/day2_util.cpp)

add_executable(day2 "${SOURCES}")

include_directories(day2 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
