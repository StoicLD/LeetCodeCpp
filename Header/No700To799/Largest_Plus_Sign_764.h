#ifndef LEETCODECPP_HEADER_NO700TO799_LARGEST_PLUS_SIGN_764_H_
#define LEETCODECPP_HEADER_NO700TO799_LARGEST_PLUS_SIGN_764_H_
#include <vector>
#include <algorithm>
using namespace std;
class Largest_Plus_Sign_764 {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> table(n, vector<int>(n, 1));
        vector<vector<int>> left(n, vector<int>(n, 1));
        vector<vector<int>> up(n, vector<int>(n, 1));
        for(auto &it : mines)
        {
            table[it[0]][it[1]] = 0;
            left[it[0]][it[1]] = 0;
            up[it[0]][it[1]] = 0;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(table[i][j] != 0)
                {
                    left[i][j] = left[i][j - 1] + 1;
                }
            }
        }

        for(int j = 0; j < n; j++)
        {
            for(int i = 1; i < n; i++)
            {
                if(table[i][j] != 0)
                {
                    up[i][j] = up[i - 1][j] + 1;
                }
            }
        }
        const int max_length = (n - 1) / 2;
        for(int length = max_length; length >= 0; length--)
        {
            const int curr_length = length * 2 + 1;
            for(int i = length; i < n - length; i++)
            {
                for(int j = length; j < n - length; j++)
                {
                    int min_length = min(left[i][j + length], up[i + length][j]);
                    if(min_length >= curr_length)
                    {
                        return length + 1;
                    }
                }
            }
        }

        return 0;
    }
};

#endif