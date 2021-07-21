//
// Created by lidong on 2021/7/4.
//

#ifndef LEETCODECPP_MAX_SUM_OF_RECTANGLE_NO_LARGER_THAN_K_363_H
#define LEETCODECPP_MAX_SUM_OF_RECTANGLE_NO_LARGER_THAN_K_363_H
using namespace std;
class Max_Sum_Of_Rectangle_No_Larger_Than_K_363 {
public:
    /**
     * 解法一 一种DP版本的解法
     * @param matrix
     * @param k
     * @return
     */
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag = m < n;
        int vec_size = flag ? m : n;
        int iterate_length = flag ? n : m;

        int curr_max = matrix[0][0];
        for(int x = 0; x < m; x++)
        {
            for(int y = 0; y < n; y++)
            {
                int i_base = (flag ? y : x);
                int j_base = (flag ? x : y);
                vector<int> accumulate_vec(vec_size - j_base, 0);
                for (int i = 0; i < iterate_length - i_base; i++)
                {
                    int curr_accumulate_sum = 0;
                    for (int j = 0; j < vec_size - j_base; j++)
                    {
                        if(flag)
                        {
                            curr_accumulate_sum += matrix[j + j_base][i + i_base];
                            accumulate_vec[j] += curr_accumulate_sum;
                        }
                        else
                        {
                            curr_accumulate_sum += matrix[i + i_base][j+ j_base];
                            accumulate_vec[j] += curr_accumulate_sum;
                        }

                            if(accumulate_vec[j] <= k && abs(accumulate_vec[j] -k) < abs(curr_max - k))
                        {
                            curr_max = accumulate_vec[j];
                        }
                        if(curr_max == k)
                        {
                            return k;
                        }
                    }
                }
            }
        }
        return curr_max;
    }
};

#endif //LEETCODECPP_MAX_SUM_OF_RECTANGLE_NO_LARGER_THAN_K_363_H
