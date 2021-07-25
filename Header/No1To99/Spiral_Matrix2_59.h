//
// Created by lidong on 2021/7/22.
//

#ifndef LEETCODECPP_SPIRAL_MATRIX2_59_H
#define LEETCODECPP_SPIRAL_MATRIX2_59_H
using namespace std;
class Spiral_Matrix2_59 {
public:
    bool needChangeDirection(int x, int y, int n, vector<vector<int>>& matrix) {
        return (x >= n || y >= n || x < 0 || y < 0 || matrix[y][x]);
    }

    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        vector<pair<int, int>> direction{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int x = 0, y = 0;
        auto curr_dir = direction[0];
        int change_times = 0;
        for(int i = 0; i < n * n; i++)
        {
            result[y][x] = i + 1;
            if(needChangeDirection(x + curr_dir.first, y + curr_dir.second, n, result))
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
#endif //LEETCODECPP_SPIRAL_MATRIX2_59_H
