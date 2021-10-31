cmake_minimum_required(VERSION 3.14)
project(Projects)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(BrainApp)
add_subdirectory(Test)
add_subdirectory(AsioTest)
