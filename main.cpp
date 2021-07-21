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

using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */


int main()
{
    std::vector<int> input_vec1{2, 3, 1, 2, 4, 3};
    Minimum_Size_Subarray_Sum_209 test;
    cout << test.minSubArrayLen2(7, input_vec1);
}
