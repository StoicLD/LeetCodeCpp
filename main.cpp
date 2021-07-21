#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "No200To299/Minimum_Size_Subarray_Sum_209.h"
#include "No900To999/Fruit_Into_Baskets_904.h"
#include "No1To99/Minimum_Window_Substring_76.h"

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
//    std::vector<int> input_vec1{3, 3, 3, 1, 2, 1, 1, 2, 2, 4, 4, 2, 1};
//    Fruit_Into_Baskets_904 test;
//    cout << test.totalFruit(input_vec1);
    string s = "aa";
    string t = "aa";
    Minimum_Window_Substring_76 test;
    cout<< test.minWindow(s, t);
}
