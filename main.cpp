#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Header/CourseSchedule_207.h"
#include "Header/QueueReconstructionByHeight_406.h"
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
    QueueReconstructionByHeight_408 q;
    vector<pair<int,int>> vec{{7,0},{4,4},{5,0},{6,1},{5,2},{7,1}};
    int m  = 2;
    m <<= 2;
    cout << m << endl;
    return 0;
}
