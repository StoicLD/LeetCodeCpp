//
// Created by lidong on 2020/5/26.
//

#include <vector>
#include <cmath>
#ifndef LEETCODECPP_UNCROSSEDLINES_H
#define LEETCODECPP_UNCROSSEDLINES_H
class SolutionList1
{
public:
    /**
     * 可以DP求解，问题本身和最长公共子序列是一样的
     * 解惑：最长公共子序列并不是连续的，所以这个问题确实等价于最长公共子序列问题
     * @param A 数组1
     * @param B 数组2
     * @return 最大连线数
     */
    int maxUncrossedLines(std::vector<int> &A, std::vector<int> &B);
};

class ContiguousArray
{
public:
    int findMaxLength(std::vector<int>& nums);
};

#endif //LEETCODECPP_UNCROSSEDLINES_H