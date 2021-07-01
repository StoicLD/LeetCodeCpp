//
// Created by lidong on 2021/6/24.
//

#ifndef LEETCODECPP_OUTOFBOUNDARYPATHS_576_H
#define LEETCODECPP_OUTOFBOUNDARYPATHS_576_H
#include <vector>
class OutOfBoundaryPaths_576
{
public:

    bool within(int maxMove, int x, int y, int start_x, int start_y) {
        return ((std::abs(x - start_x) + std::abs(y - start_y)) <= maxMove);
    }

    bool isBorder(int x, int y, int m, int n) {
        return x < 0 || x >= m || y < 0 || y >= n;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        // dp解法
        const int MOD = 1000000000 + 7;
        int upper_bound_x = std::max(startRow - maxMove, 0);
        int upper_bound_y = startColumn;
        int left_bound_x = startRow;
        int left_bound_y = std::max(startColumn - maxMove, 0);
        int right_bound_x = startRow;
        int right_bound_y = std::max(startColumn + maxMove, 0);
        int down_bound_x = std::max(startRow + maxMove, 0);
        int down_bound_y = startColumn;

        int y_width = right_bound_y - left_bound_y;
        int x_width = down_bound_x - upper_bound_x;
        int offset_x = upper_bound_x;
        int offset_y = left_bound_y;

        std::vector<int> dp1(x_width * y_width, 0);
        std::vector<int> dp2(x_width * y_width, 0);
        std::vector<int> &curr_dp = dp1;
        std::vector<int> &pre_dp = dp2;
        for(int move = 0; move <= maxMove; move++)
        {
            pre_dp = move % 2 ? dp2 : dp1;
            curr_dp = move % 2 ? dp1 : dp2;
            for (int i = 0; i < y_width; i++)
            {
                for (int j = 0; j < x_width; j++)
                {
                    if (within(maxMove, j, i, startRow - offset_x, startColumn - offset_y))
                    {
                        if (move == 0)
                        {
                            if (isBorder(j + 1, i, m, n))
                            {
                                curr_dp[i + j * y_width] += 1;
                            }
                            if (isBorder(j - 1, i, m, n))
                            {
                                curr_dp[i + j * y_width] += 1;
                            }
                            if (isBorder(j, i + 1, m, n))
                            {
                                curr_dp[i + j * y_width] += 1;
                            }
                            if (isBorder(j, i - 1, m, n))
                            {
                                curr_dp[i + j * y_width] += 1;
                            }
                        }
                        else
                        {
                            curr_dp[i + j * y_width] = pre_dp[i + j * y_width];
                            if (within(maxMove, j + 1, i, startRow - offset_x, startColumn - offset_y))
                            {
                                curr_dp[i + j * y_width] += pre_dp[i + (j + 1) * y_width];
                                curr_dp[i + j * y_width] %= MOD;
                            }
                            if (within(maxMove, j - 1, i, startRow - offset_x, startColumn - offset_y))
                            {
                                curr_dp[i + j * y_width] += pre_dp[i + (j - 1) * y_width];
                                curr_dp[i + j * y_width] %= MOD;
                            }
                            if (within(maxMove, j, i + 1, startRow - offset_x, startColumn - offset_y))
                            {
                                curr_dp[i + j * y_width] += pre_dp[i + 1 + j * y_width];
                                curr_dp[i + j * y_width] %= MOD;
                            }
                            if (within(maxMove, j, i - 1, startRow - offset_x, startColumn - offset_y))
                            {
                                curr_dp[i + j * y_width] += pre_dp[i - 1 + j * y_width];
                                curr_dp[i + j * y_width] %= MOD;
                            }
                        }
                    }
                }
            }
        }
        return curr_dp[startColumn - offset_y + y_width * (startRow - offset_x)];
    }
};

#endif //LEETCODECPP_OUTOFBOUNDARYPATHS_576_H
