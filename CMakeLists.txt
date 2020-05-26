cmake_minimum_required(VERSION 3.16)
include_directories(Header)
project(LeetCodeCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeetCodeCpp main.cpp Source/SolutionList1.cpp Header/SolutionList1.h Header/Test.h)