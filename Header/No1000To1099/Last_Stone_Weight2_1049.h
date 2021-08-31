//
// Created by Dong Li on 8/30/21.
//

#ifndef LEETCODECPP_HEADER_NO1000TO1099_LAST_STONE_WEIGHT2_1049_H_
#define LEETCODECPP_HEADER_NO1000TO1099_LAST_STONE_WEIGHT2_1049_H_
class Last_Stone_Weight2_1049 {
public:

    /**
     * 原始的DP解法
     * 这个问题实质上是一个变相的背包，关键在于两点，一是把问题转换为一个背包问题
     * 二就是解决这个变相的转换后的背包问题
     * 从一个例子里来想这个问题，比如stones = [2, 4, 7, 3, 1, 8]
     * 问题要求我们从stones中选择两个石头相撞，也就是选择两个数相减取绝对值，随后得到的数再
     * 放回stones里面，继续重复这个步骤，直到得到一个最小的数值。
     * 但换个思路想，相当于在每个数字前放上加减号，比如
     * -2 +4 -7 -3 +1 +8
     * 这种组合下得到了一个最小值1。我们把这些数字分一下组，所有加号的在一组，所有减号的在一组
     * 于是得到了 {2, 3, 7}, {4, 1, 8} 两组，然后我们可以发现这个问题等价成了两组数字相减
     * 而要求得最小值就是得到两组数字相减的最小值。如果要这个数最小，那么我们要尽量的使得两组数字
     * 的分别求和大小接近，如果说所有的数字的和是sum，那么每组数字越接近sum / 2就越好
     * 因此这个问题变成了，如何组成一个大小接近sum / 2的背包。
     * dp数组的第一个维度就是stones中的序号，第二个维度则是背包大小（从 0 到 sum / 2）
     * dp[i][j] 表示在stones数组的前i个元素中选取，组成大小为j的背包是否可行，所以是一个bool数值
     * 状态转移方程如下所示，
     * dp[i][j] = dp[i - 1][j] OR dp[i - 1][j - stones[i]]
     * 表明为 在stones数组的前i个元素中选取，组成大小为j的背包是否可行，取决于=》在前i - 1个元素中选取，组成大小为j的背包是否可行
     * 或者在前i - 1个元素中选取，组成大小为 j - stones[i]，也就是不把当前元素放入组成背包的集合。
     * 如果这两者有一个可行就是ok的
     * @param stones
     * @return
     */
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(1501, false));
        // 尽可能的凑成一个容量接近 sum / 2的背包
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += stones[i];
            dp[i][0] = true;
            dp[i][stones[i]] = true;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum / 2; j++)
            {
                // 从前i个石头中选择，是否能够组成容量为j的背包？
                // （1）如果从i-1个石头中选择可以组成，那么就ok
                // （2）如果前i个石头中可以组成容量为j - stones[i]的背包，那么也可以
                dp[i][j] = dp[i - 1][j] || (j - stones[i] >= 0 ? dp[i - 1][j - stones[i]] : false);
            }
        }
        // 最后我们得到的dp数组是包含了小于sum / 2的情况下所有的组成可行性情况，所以我们从sum / 2 开始递减搜索
        for(int i = sum / 2; i > 0; i--)
        {
            if(dp[n - 1][i])
            {
                return sum - i - i;
            }
        }
        return sum;
    }


    int lastStoneWeightII2(vector<int>& stones) {
        vector<bool> dp(1501, false);
        int sum = 0;
        for(auto stone : stones)
        {
            sum += stone;
            // 一维的时候此处不能设置为true，因为意义被改变了
            // 二维的时候dp[i][stone]可以被设置为true
            // 但是一维的时候此处不一定是可以选的，因为dp[i][stone]不等价于此处的dp[stone]
//            dp[stone] = true;
        }
        dp[0] = true;

        for(int stone : stones)
        {
            for(int j = sum / 2; j > 0; j--)
            {
                if(j - stone >= 0)
                {
                    dp[j] = dp[j] || dp[j - stone];
                }
            }
        }

        for(int j = sum / 2; j > 0; j--)
        {
            if(dp[j])
            {
                return sum - j - j;
            }
        }
        return sum;
    }

};
#endif //LEETCODECPP_HEADER_NO1000TO1099_LAST_STONE_WEIGHT2_1049_H_



