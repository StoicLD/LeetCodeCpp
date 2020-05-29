cmake_minimum_required(VERSION 3.16)
include_directories(Header)
project(LeetCodeCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeetCodeCpp main.cpp Header/Test.h Source/PossibleBipartition.cpp Source/UncrossedLines.cpp Source/ContiguousArray.cpp Header/ContiguousArray.h Header/UncrossedLines.h Header/PossibleBipartition.h Header/CountingBits.h Header/CourseSchedule.h)