cmake_minimum_required(VERSION 3.16)
include_directories(Header)
project(LeetCodeCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeetCodeCpp main.cpp Header/Test.h Source/PossibleBipartition_886.cpp Source/UncrossedLines_1035.cpp Source/ContiguousArray_525.cpp Header/ContiguousArray_525.h Header/UncrossedLines_1035.h Header/PossibleBipartition_886.h Header/CountingBits_338.h Header/CourseSchedule_207.h Header/KClosestPointsToOrigin_973.h Header/EditDistance_72.h Header/InvertBinaryTree_226.h Header/TreeNode.h)