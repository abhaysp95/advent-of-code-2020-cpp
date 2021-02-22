set(SOURCES src/main.cpp
	inc/day7_util.hpp
	src/day7_util.cpp)

add_executable(day7 "${SOURCES}")

include_directories(day7 inc src)

configure_file(input_demo.txt "${CMAKE_CURRENT_BINARY_DIR}/input_demo.txt")
configure_file(input_main.txt "${CMAKE_CURRENT_BINARY_DIR}/input_main.txt")
