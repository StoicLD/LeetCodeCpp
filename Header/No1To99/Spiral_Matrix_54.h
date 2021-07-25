//
// Created by lidong on 2021/7/22.
//

#ifndef LEETCODECPP_SPIRAL_MATRIX_54_H
#define LEETCODECPP_SPIRAL_MATRIX_54_H

using namespace std;
class Spiral_Matrix_54 {
public:
    bool needChangeDirection(int x, int y, int n, int m, vector<vector<int>>& matrix) {
        return (x >= n || y >= m || x < 0 || y < 0 || matrix[y][x] == 0);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result(m * n, 0);
        vector<pair<int, int>> direction{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int x = 0, y = 0;
        auto curr_dir = direction[0];
        int change_times = 0;
        for(int i = 0; i < m * n; i++)
        {
            result[i] = matrix[y][x];
            matrix[y][x] = 0;
            if(needChangeDirection(x + curr_dir.first, y + curr_dir.second, n, m, matrix))
            {
                change_times++;
                curr_dir = direction[change_times % 4];
            }
            x += curr_dir.first;
            y += curr_dir.second;
        }
        return result;
    }
};
#endif //LEETCODECPP_SPIRAL_MATRIX_54_H
