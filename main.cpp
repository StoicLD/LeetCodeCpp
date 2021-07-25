#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "No700To799/Design_Linked_List_707.h"
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
    std::vector<vector<int>> input_vec1{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//    Fruit_Into_Baskets_904 test;
//    cout << test.totalFruit(input_vec1);
    MyLinkedList test;
    test.addAtIndex(0, 10);
    test.addAtIndex(0, 20);
    test.addAtIndex(1, 30);
    test.get(0);

}
