#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "No800To899/Sum_of_Distances_in_Tree_834.h"
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
    Sum_of_Distances_in_Tree_834 test;
    vector<vector<int>> test_vec{{3,2},{0,1},{4,2},{0,2},{2,5}};
    auto result = test.sumOfDistancesInTree2(6, test_vec);
    for(auto i : result)
    {
        cout << "[" << i << "], ";
    }

}
