//
// Created by lidong on 2020/6/8.
//

#ifndef LEETCODECPP_COINCHANGE2_528_H
#define LEETCODECPP_COINCHANGE2_528_H
#include <vector>
#include <algorithm>
using namespace std;
class CoinChange2_518
{
public:
    int numOfChanges;
    int change(int amount, vector<int>& coins)
    {
        /*
         * dp数组的定义非常的重要，如果是优化空间前的数组，那么是一个二维的数组
         * dp[i][j]表明的是至多使用前i中coin的情况下组成面额为j有都少种组合。
         * dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]
         * 优化空间之后的dp[i]相当于当前只用coin
         */
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(auto coin : coins)
        {
            for(int i = coin; i <= amount; i++)
            {
                // 第一轮遍历相当于只使用coins[0]
                // 第二轮遍历相当于在可以使用coins[0]的基础上再使用coins[1]
                // 以coins = [5,1,2], k = 5为例
                // dp[1] = 0, dp[2] = 0, dp[3] = 0, dp[4] = 0,dp[5] = 1
                // dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 1,dp[5] = 1 + dp[5 - 2] = 2
                // dp[1] = 1, dp[2] = 1 + dp[2 - 0] = 2, dp[3] = 1 + dp[3 - 2] = 2, dp[4] = 1 + dp[4 - 2] = 3,dp[5] = 2 + dp[5 - 2] = 4
                // 之所以可以优化是因为原先的二维dp中，如果我们只看第一个纬度i，发现这个维度dp[i][j]只依赖于前一个dp[i-1][j]和dp[i][j - coins[i]]
                // dp[i - 1][j]可以现存储在dp[i][j]里面，因为后续i继续递增，i-1不会再次被用到了，因此可以被覆盖掉。
                // 优化的关键是在一定遍历顺序下（top to down or down to top），有些子问题的结果不会再次被用到，可以被覆盖，因此就不需要额外的存储空间
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }

    /**
     * 回溯法
     * @param amount
     * @param coins
     * @return
     */
    int change2(int amount, vector<int>& coins)
    {
        if(amount == 0)
            return 1;
        sort(coins.begin(), coins.end());
        numOfChanges = 0;
        for(int i = 0; i < coins.size(); i++)
            changesTracingBackHelper(amount - coins[i], i, coins);
        return numOfChanges;
    }

    void changesTracingBackHelper(int amount, int index, vector<int>& coins)
    {
        if(amount <= 0)
        {
            if(amount == 0)
                numOfChanges++;
            return;
        }
        for(int i = 0; i <= index; i++)
            changesTracingBackHelper(amount - coins[i], i, coins);
    }
};

#endif //LEETCODECPP_COINCHANGE2_528_H
