//
// Created by Dong Li on 8/22/21.
//

#ifndef LEETCODECPP_HEADER_NO1TO99_UNIQUE_BINARY_SEARCH_TREES_96_H_
#define LEETCODECPP_HEADER_NO1TO99_UNIQUE_BINARY_SEARCH_TREES_96_H_
#include <vector>
using namespace std;

class Unique_Binary_Search_Trees_76 {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

#endif //LEETCODECPP_HEADER_NO1TO99_UNIQUE_BINARY_SEARCH_TREES_96_H_
