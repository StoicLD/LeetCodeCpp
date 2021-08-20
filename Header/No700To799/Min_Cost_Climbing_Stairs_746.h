//
// Created by Dong Li on 8/19/21.
//

#ifndef LEETCODECPP_HEADER_NO700TO799_MIN_COST_CLIMBING_STAIRS_746_H_
#define LEETCODECPP_HEADER_NO700TO799_MIN_COST_CLIMBING_STAIRS_746_H_
#include <algorithm>

using namespace std;

class Min_Cost_Climbing_Stairs_746 {
public:

    /**
     * 注意题目，实际上是跳转到数组最后一个的后面一个元素才算是top
     * @param cost
     * @return
     */
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 2)
        {
            return min(cost[0], cost[1]);
        }

        int min_cost1 = 0;
        int min_cost2 = 0;
        int result_cost = 0;
        for(int i = 2; i < cost.size(); i++)
        {
            result_cost = min(min_cost1 + cost[i - 2], min_cost2 + cost[i - 1]);
            min_cost1 = min_cost2;
            min_cost2 = result_cost;
        }
        return min(min_cost1 + cost[cost.size() - 2], min_cost2 + cost[cost.size() - 1]);
    }

    int minCostClimbingStairs2(vector<int>& cost) {
        int dp0 = cost[0];
        int dp1 = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int dpi = min(dp0, dp1) + cost[i];
            dp0 = dp1; // 记录一下前两位
            dp1 = dpi;
        }
        return min(dp0, dp1);
    }
};

#endif //LEETCODECPP_HEADER_NO700TO799_MIN_COST_CLIMBING_STAIRS_746_H_
