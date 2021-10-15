cmake_minimum_required(VERSION 3.14)
project(Examples)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(BrainApp)
add_subdirectory(Test)
