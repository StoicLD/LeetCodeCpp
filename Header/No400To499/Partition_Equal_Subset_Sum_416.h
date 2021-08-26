//
// Created by Dong Li on 8/23/21.
//

#ifndef LEETCODECPP_HEADER_NO400TO499_PARTITION_EQUAL_SUBSET_SUM_416_H_
#define LEETCODECPP_HEADER_NO400TO499_PARTITION_EQUAL_SUBSET_SUM_416_H_
class Partition_Equal_Subset_Sum_416 {
public:
    /**
     * dp解法，实际上这是一个0-1背包问题
     * 题目要求从分成两组，每组数的和是相等的，那么问题等价于从原数组中找到部分元素
     * 和是sum/2，这个问题等价于一个重量为sum/2的背包，要求我们刚好放满整个背包
     * dp[i][j]表明前i个元素中取部分元素 是否 正好能组成重量j的背包，
     * dp[i][j] = dp[i-1][j] || dp[i - 1][j - nums[i]]
     * 解释：如果前i-1个元素中选取部分可以组成j的重量的背包，那么前i个元素也可以
     * 如果前i-1个元素中选取部分元素可以组成重量为j-nums[i]的背包，那么把当前元素加进去之后就正好可以组成重量为j的背包了
     * @param nums
     * @return
     */
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int sum = 0;
        for(auto e : nums)
        {
            sum += e;
        }
        if(sum != sum / 2 * 2)
        {
            return false;
        }
        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for(int i = 0; i < dp.size(); i++)
        {
            dp[i][0] = true;
        }
        for(int i = 0; i < dp.size(); i++)
        {
            for(int j = 0; j < dp[0].size(); j++)
            {
                if(i == 0)
                {
                    dp[i][j] = nums[i] == j;
                }
                else if(j - nums[i] >= 0)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }

    /**
     * dp解法2，空间优化的版本
     * 也就是使用一纬数组的方法
     * @param nums
     * @return
     */
    bool canPartition(vector<int>& nums)
    {

    }

};
#endif //LEETCODECPP_HEADER_NO400TO499_PARTITION_EQUAL_SUBSET_SUM_416_H_
