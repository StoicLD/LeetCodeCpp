//
// Created by Dong Li on 9/4/21.
//

#ifndef LEETCODECPP_HEADER_NO400TO499_TARGET_SUM_494_H_
#define LEETCODECPP_HEADER_NO400TO499_TARGET_SUM_494_H_
#include <algorithm>
class Target_Sum_494 {
public:
    int findTargetSumWays2(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(1001, 0));

        for(int i = 0; i < nums.size(); i++)
        {
            dp[i][nums[i]] += 1;
            dp[i][0] = 1;
        }

        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            for(int j = 0; j <= target; j++)
            {
                if(i >= 1)
                {
                    dp[i][j] = dp[i - 1][j];
                    if(j >= nums[i])
                    {
                        dp[i][j] += dp[i - 1][j - nums[i]];
                    }
                }
            }
        }
        if(target > sum || target < -sum || (sum + target) % 2 != 0)
        {
            return 0;
        }
        return dp[nums.size() - 1][(sum + target) / 2];
    }



    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> dp(1001, 0);
        dp[0] = 1;
        int sum = 0;
        for(int i : nums)
        {
            sum += i;
        }
        int bag_size = (sum + target) / 2;
        if(target > sum || target < -sum || bag_size % 2 != 0)
        {
            return 0;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = bag_size; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bag_size];
    }

    int findTargetSumWays3(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (abs(S) > sum) return 0; // 此时没有方案
        if ((S + sum) % 2 == 1) return 0; // 此时没有方案
        int bagSize = (S + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
#endif //LEETCODECPP_HEADER_NO400TO499_TARGET_SUM_494_H_
