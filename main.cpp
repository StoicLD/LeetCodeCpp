#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <KClosestPointsToOrigin.h>
#include "Header/CourseSchedule.h"
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


/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */
int main() {

    vector<vector<int>> vecs1{vector<int>{1,10}, vector<int>{1,2}, vector<int>{2,1}, vector<int>{11,2}};

    vector<vector<int>> vecs2{vector<int>{1, -1}, vector<int>{1,3}, vector<int>{2, -2}, vector<int>{12, -2}, vector<int>{1, -1}};

    KClosestPointsToOrigin_973 k;
    auto result = k.kClosest(vecs2, 1);

    for(auto vec : result)
    {
        cout << to_string(vec[0]) << " " << to_string(vec[1]) << endl;
    }
    return 0;
}
