//
// Created by Dong Li on 8/24/21.
//

#ifndef LEETCODECPP_HEADER_NO300TO399_COIN_CHANGE_322_H_
#define LEETCODECPP_HEADER_NO300TO399_COIN_CHANGE_322_H_
#include <vector>
using namespace std;
class Coin_Change_322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(coins[j] <= i && dp[i - coins[j]] != INT32_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};

#endif //LEETCODECPP_HEADER_NO300TO399_COIN_CHANGE_322_H_
