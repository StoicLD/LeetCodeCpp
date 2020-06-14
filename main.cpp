#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include "LargestDivisibleSubset_368.h"
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
    LargestDivisibleSubset_368 l;
    vector<int> vec{2,4,6,8,9,15,16,17,30};
    auto result =  l.largestDivisibleSubset(vec);
    for(auto i : result)
    {
        cout << i << endl;
    }
    return 0;
}
