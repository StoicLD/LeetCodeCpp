//
// Created by lidong on 2020/5/26.
//
//TODO LeetCode 1035
#include "SolutionList1.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int SolutionList1::maxUncrossedLines(vector<int> &A, vector<int> &B)
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

int ContiguousArray::findMaxLength(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    //vector<int> dp(nums.size());
    map<int, int> dp;
    dp.insert(make_pair(0, -1));
    int result = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        count += nums[i] == 0 ? -1 : 1;
        if (dp.find(count) != dp.end())
        {
            result = max(result, i - dp.at(count));
        }
        else
        {
            dp.insert(make_pair(count, i));
        }
    }
    return result;
}