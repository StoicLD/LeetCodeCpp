#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "No400To499/Assign_Cookies_455.h"
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
    Assign_Cookies_455 test;
    vector<int> g1{11, 21, 31, 41};
    vector<int> s1{1, 4, 30, 40};
    cout << test.findContentChildren(g1, s1);
//    Fruit_Into_Baskets_904 test;
//    cout << test.totalFruit(input_vec1);

}
