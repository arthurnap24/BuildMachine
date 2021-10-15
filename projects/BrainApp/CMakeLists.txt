cmake_minimum_required(VERSION 3.14)
project(BrainApp)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(BrainApp DataSource.cpp SearchItem.cpp main.cpp)
target_link_libraries(BrainApp ${GTEST_LIBRARIES} pthread)
