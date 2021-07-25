//
// Created by lidong on 2020/6/3.
//

#ifndef LEETCODECPP_TWOCITYSCHEDULING_1029_H
#define LEETCODECPP_TWOCITYSCHEDULING_1029_H

#include <vector>
#include <algorithm>

using namespace std;

//TODO LeetCode 1029
class TwoCityScheduling_1029
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        // [[10,20],[30,200],[400,50],[30,20]]
        // [[100,20],[130,20],[400,50],[30,20]]
        return 1;
    }

    /**
     * 把去往城市A和城市B花费的差值排序，前一半划给城市A
     * 后一半划给城市B
     * @param cs
     * @param res
     * @return
     */
    int twoCitySchedCost2(vector<vector<int>> &cs, int res = 0)
    {
        sort(begin(cs), end(cs), [](vector<int> &v1, vector<int> &v2) {
            return (v1[0] - v1[1] < v2[0] - v2[1]);
        });
        for (auto i = 0; i < cs.size() / 2; ++i)
        {
            res += cs[i][0] + cs[i + cs.size() / 2][1];
        }
        return res;
    }
};


#endif //LEETCODECPP_TWOCITYSCHEDULING_1029_H
