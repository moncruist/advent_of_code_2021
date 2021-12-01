cmake_minimum_required(VERSION 3.20)
project(advent_of_code_2021)

set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(GMock)
find_package(GTest)
find_package(Boost COMPONENTS program_options REQUIRED)

add_subdirectory(day1)
