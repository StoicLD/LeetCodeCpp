//
// Created by lidong on 2020/5/27.
//

#ifndef LEETCODECPP_UNCROSSEDLINES_H
#define LEETCODECPP_UNCROSSEDLINES_H
#include <vector>
#include <algorithm>
using namespace std;
//TODO LeetCode 1035
class UncrossedLines_1035
{
public:
    /**
     * 可以DP求解，问题本身和最长公共子序列是一样的
     * 解惑：最长公共子序列并不是连续的，所以这个问题确实等价于最长公共子序列问题
     * @param A 数组1
     * @param B 数组2
     * @return 最大连线数
     */
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int m = A.size(), n = B.size();
        //这不是标准C++的写法，不允许变量长度。GCC是允许的，然而MSVC不允许
        vector<vector<int> > dp(m + 1);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (dp[i].empty())
                    dp[i] = vector<int>(n + 1);
                dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
            }
        return dp[m][n];
    }
};


#endif //LEETCODECPP_UNCROSSEDLINES_H
