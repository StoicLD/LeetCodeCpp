#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include "CheapestFlightsWithinKStops_787.h"
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
    CheapestFlightsWithinKStops_787 cf;
    vector<vector<int>> vec{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << cf.findCheapestPrice(3, vec, 0 , 2, 1) << endl;
    cout << cf.findCheapestPrice(3, vec, 0 , 2, 0) << endl;

}
