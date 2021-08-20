//
// Created by Dong Li on 8/19/21.
//

#ifndef LEETCODECPP_HEADER_NO1TO99_UNIQUE_PATHS2_63_H_
#define LEETCODECPP_HEADER_NO1TO99_UNIQUE_PATHS2_63_H_
#include <vector>
using namespace std;
class Unique_Paths2_63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }
        obstacleGrid[0][0] = -1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] != 1)
                {
                    if(i > 0)
                    {
                        obstacleGrid[i][j] += (obstacleGrid[i - 1][j] == 1 ? 0 : obstacleGrid[i - 1][j]);
                    }
                    if(j > 0)
                    {
                        obstacleGrid[i][j] += (obstacleGrid[i][j - 1] == 1 ? 0 : obstacleGrid[i][j - 1]);
                    }
                }
            }
        }
        return -obstacleGrid[m - 1][n - 1];
    }
};
#endif //LEETCODECPP_HEADER_NO1TO99_UNIQUE_PATHS2_63_H_
