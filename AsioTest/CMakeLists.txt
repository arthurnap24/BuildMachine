cmake_minimum_required(VERSION 3.14)
project(AsioTest)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
add_executable(AsioTest TimerExamples.cpp Printer.cpp PrinterStrand.cpp main.cpp)
target_link_libraries(AsioTest ${GTEST_LIBRARIES} pthread)
