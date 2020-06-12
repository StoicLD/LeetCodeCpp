cmake_minimum_required(VERSION 3.16)
include_directories(Header)
project(LeetCodeCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeetCodeCpp main.cpp Header/Test.h Source/PossibleBipartition_886.cpp Source/UncrossedLines_1035.cpp Source/ContiguousArray_525.cpp Header/ContiguousArray_525.h Header/UncrossedLines_1035.h Header/PossibleBipartition_886.h Header/CountingBits_338.h Header/CourseSchedule_207.h Header/KClosestPointsToOrigin_973.h Header/EditDistance_72.h Header/InvertBinaryTree_226.h Header/TreeNode.h Header/ListNode.h Header/DeleteNodeInALinkedList_237.h Header/TwoCityScheduling_1029.h Header/ReverseString_344.h Header/RandomPickWithWeight_528.h Header/QueueReconstructionByHeight_406.h Header/CoinChange2_528.h Header/PowerOfTwo_231.h Header/IsSubsequence_392.h Header/SearchInsertPosition_35.h Header/SortColors_75.h)