//
// Created by Dong Li on 8/19/21.
//

#ifndef LEETCODECPP_HEADER_NO300TO399_INTEGER_BREAK_343_H_
#define LEETCODECPP_HEADER_NO300TO399_INTEGER_BREAK_343_H_
#include <algorithm>
#include <math.h>

using namespace std;

class Integer_Break_343 {
public:
    /**
     * 需要证明的一种数论解法
     * @param n
     * @return
     */
    int integerBreak(int n) {
        int dp[3] = {1, 2, 4};
        if(n <= 3)
        {
            return dp[n - 1];
        }
        int product = 1;
        while(n - 3 > 3)
        {

            product *= 3;
            n -= 3;
        }
        return product * (n <= 0 ? 1 : n);
    }

    /**
     * dp的一种解法
     * @param n
     * @return
     */
    int integerBreak2(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n ; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};

#endif //LEETCODECPP_HEADER_NO300TO399_INTEGER_BREAK_343_H_
