//
// Created by lidong on 2021/6/22.
//

#ifndef LEETCODECPP_UNIQUEBINARYSEARCHTREES_96_H
#define LEETCODECPP_UNIQUEBINARYSEARCHTREES_96_H
#include <vector>
class UniqueBinarySearchTrees96 {
public:
    /**
     * @brief dp解法
     * @param n
     * @return
     */
    int numTrees(int n) {
        std::vector dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

#endif //LEETCODECPP_UNIQUEBINARYSEARCHTREES_96_H
