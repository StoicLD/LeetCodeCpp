//
// Created by Dong Li on 8/19/21.
//

#ifndef LEETCODECPP_HEADER_NO1TO99_UNIQUE_PATHS_62_H_
#define LEETCODECPP_HEADER_NO1TO99_UNIQUE_PATHS_62_H_
class Unique_Paths_62 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if(j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

#endif //LEETCODECPP_HEADER_NO1TO99_UNIQUE_PATHS_62_H_
