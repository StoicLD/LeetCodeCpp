#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "No1To99/Unique_Binary_Search_Trees_96.h"
#include "No600To699/Two_Sum4_Input_is_a_BST_653.h"
#include "No300To399/Verify_Preorder_Serialization_of_a_Binary_Tree_331.h"
#include "No600To699/Sum_of_Square_Numbers_633.h"
#include "No1000To1099/Last_Stone_Weight2_1049.h"
using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */

struct TestNode {
    int val;
};

int main()
{
    Last_Stone_Weight2_1049 test;
    vector<int> vec{31,26,33,21,40};
    cout << test.lastStoneWeightII2(vec);
}
