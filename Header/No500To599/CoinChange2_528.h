//
// Created by lidong on 2020/6/8.
//

#ifndef LEETCODECPP_COINCHANGE2_528_H
#define LEETCODECPP_COINCHANGE2_528_H
#include <vector>
#include <algorithm>
using namespace std;
class CoinChange2_528
{
public:
    int numOfChanges;
    int change(int amount, vector<int>& coins)
    {
        vector<int> dp(amount, 0);
        dp[0] = 1;
        for(auto coin : coins)
        {
            for(int i = coin; i <= amount; i++)
            {
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
