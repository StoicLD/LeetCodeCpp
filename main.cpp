#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "No1To99/UniqueBinarySearchTrees_96.h"
#include "No500To599/OutOfBoundaryPaths_576.h"
#include "No300To399/CountOfSmallerNumbersAfterSelf_315.h"
#include "No700To799/Binary_Search_704.h"
#include "No1To99/Remove_Element_27.h"
using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */


int main()
{
    Remove_Element_27 test;
    std::vector input_vec1{1, 3, 4, 6, 7, 4, 2, 4, 4};

    std::vector input_vec2{3, 2, 2, 3};
    std::vector input_vec3{1, 3, 4, 6};
    std::vector input_vec4{1, 3};

    cout << test.removeElement(input_vec1, 4) << endl;
    for(auto i : input_vec1) {
        cout << i << ", ";
    }

    cout << endl;
    cout << test.removeElement(input_vec2, 3) << endl;
    for(auto i : input_vec2) {
        cout << i << ", ";
    }
}
