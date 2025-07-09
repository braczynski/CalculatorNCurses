cmake_minimum_required(VERSION 3.10)
project(CalculatorNCurses)

set(CMAKE_CXX_STANDARD 11)

# Find ncurses
find_package(Curses REQUIRED)

# Source files
file(GLOB SOURCES "src/*.cpp")

add_executable(CalculatorNCurses ${SOURCES})

target_include_directories(CalculatorNCurses PRIVATE 
${CMAKE_SOURCE_DIR}/include
${CURSES_INCLUDE_DIR}
)

set_target_properties(CalculatorNCurses PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
target_link_libraries(CalculatorNCurses ${CURSES_LIBRARIES})
