//
// Created by Dong Li on 8/23/21.
//

#ifndef LEETCODECPP_HEADER_LAST_STONE_WEIGHT2_1049_H_
#define LEETCODECPP_HEADER_LAST_STONE_WEIGHT2_1049_H_
class Last_Stone_Weight2_1049 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stone.size();
        int largest = 0;
        for(auto e : stones)
        {
            largest = max(e, largest);
        }
        vector<vector<bool>> dp(n, vector<int>(largest + 1, false));
        dp[0][stones[0]] = true;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < largest + 1; j++)
            {
                for(int k = 0; k < largest + 1; k++)
                {
                    if(dp[])
                }
            }
        }
    }
};
#endif //LEETCODECPP_HEADER_LAST_STONE_WEIGHT2_1049_H_
