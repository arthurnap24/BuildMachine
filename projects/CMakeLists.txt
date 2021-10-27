cmake_minimum_required(VERSION 3.14)
project(Projects)

option(BUILD_ALL "Build all projects in the projects/ directory" ON)
option(BUILD_BrainApp "Build BrainApp example only" OFF)
option(BUILD_Test "Build Test example only" OFF)
option(BUILD_AsioTest "Build AsioTest example only" OFF)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if (BUILD_BrainApp OR BUILD_Test OR BUILD_AsioTest)
    set(BUILD_ALL OFF)
endif()

if (BUILD_BrainApp OR BUILD_ALL)
    add_subdirectory(BrainApp)
endif()
if (BUILD_Test OR BUILD_ALL)
    add_subdirectory(Test)
endif()
if (BUILD_AsioTest OR BUILD_ALL)
    add_subdirectory(AsioTest)
endif()
