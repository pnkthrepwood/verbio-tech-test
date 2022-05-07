cmake_minimum_required(VERSION 3.14)
project(format_numbers)
set(CMAKE_CXX_STANDARD 11)

add_executable(format_numbers_test test.cpp)
target_link_libraries(format_numbers_test gtest)
target_link_libraries(format_numbers_test pthread)

