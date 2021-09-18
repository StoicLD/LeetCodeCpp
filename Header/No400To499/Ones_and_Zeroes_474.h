//
// Created by Dong Li on 9/6/21.
//

#ifndef LEETCODECPP_HEADER_NO400TO499_ONES_AND_ZEROES_474_H_
#define LEETCODECPP_HEADER_NO400TO499_ONES_AND_ZEROES_474_H_
class Ones_and_Zeroes_474 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        auto length = strs.size();
        vector<vector<vector<int>>> dp(length, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        vector<vector<int>> zero_one_table(length, vector<int>(2, 0));
        for(int i = 0; i < strs.size(); i++)
        {
            for(auto c : strs[i])
            {
                if(c == '0')
                {
                    zero_one_table[i][0]++;
                }
                else
                {
                    zero_one_table[i][1]++;
                }
            }
            if(zero_one_table[i][0] <= m && zero_one_table[i][1] <= n)
                dp[i][zero_one_table[i][0]][zero_one_table[i][1]] = 1;
        }

        int result = 0;
        for(int i = 1; i < length; i++)
        {
            for(int num_of_zeros = 0; num_of_zeros <= m; num_of_zeros++)
            {
                for(int num_of_ones = 0; num_of_ones <= n; num_of_ones++)
                {
                    if(num_of_zeros - zero_one_table[i][0] >= 0 && num_of_ones - zero_one_table[i][1] >= 0)
                    {
                        dp[i][num_of_zeros][num_of_ones] = max(dp[i - 1][num_of_zeros][num_of_ones], dp[i - 1][num_of_zeros - zero_one_table[i][0]][num_of_ones - zero_one_table[i][1]] + 1);
                    }
                    else
                    {
                        dp[i][num_of_zeros][num_of_ones] = max(dp[i][num_of_zeros][num_of_ones], dp[i - 1][num_of_zeros][num_of_ones]);
                    }
                    result = max(dp[i][num_of_zeros][num_of_ones], result);
                }
            }
        }

        return result;
    }


    /**
     *
     * @param strs
     * @param m
     * @param n
     * @return
     */
    int findMaxForm2(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0)); // 默认初始化0
        for (string str : strs) { // 遍历物品
            int oneNum = 0, zeroNum = 0;
            for (char c : str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            for (int i = m; i >= zeroNum; i--) { // 遍历背包容量且从后向前遍历！
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
#endif //LEETCODECPP_HEADER_NO400TO499_ONES_AND_ZEROES_474_H_
