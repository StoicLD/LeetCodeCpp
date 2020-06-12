#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "SortColors_75.h"
using namespace std;

class myComparator
{
public:
    int operator() (const vector<int>& p1, const vector<int>& p2)
    {
        if(p1.size() != 2 && p2.size() != 2)
            return 0;
        return (p1[0] * p1[0] + p1[1] * p1[1]) >= (p2[0] * p2[0] + p2[1] * p2[1]);
    }

    static int compare (const vector<int>& p1, const vector<int>& p2)
    {
        if(p1.size() != 2 && p2.size() != 2)
            return 0;
        return (p1[0] * p1[0] + p1[1] * p1[1]) >= (p2[0] * p2[0] + p2[1] * p2[1]);
    }
};

template <typename Container>
void printElement(Container& c)
{
    for(auto e : c)
    {
        cout << e << " ";
    }
    cout << endl;
}
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */
int main() {
    SortColors_75 s;
    vector<int> nums1{2,1,0,0,1,2,2,1,1};
    vector<int> nums2{2,2,1,1,0,0,1,2,2,1,1};
    vector<int> nums3{1,0,1,2,1,0,0,1,2,2,1,1};
    vector<int> nums4{2,2,0,1,1,0,0,1,2,2,1,1};
    vector<int> nums5{1,0,2,0,1,0,0,1,2,2,1,1};

    s.sortColors(nums1);
    s.sortColors(nums2);
    s.sortColors(nums3);
    s.sortColors(nums4);
    s.sortColors(nums5);



    printElement(nums1);
    printElement(nums2);
    printElement(nums3);
    printElement(nums4);
    printElement(nums5);

    return 0;
}
