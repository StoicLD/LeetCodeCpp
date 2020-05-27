//
// Created by lidong on 2020/5/27.
//

#ifndef LEETCODECPP_POSSIBLEBIPARTITION_H
#define LEETCODECPP_POSSIBLEBIPARTITION_H

#include <vector>
#include <queue>
using namespace std;

//TODO LeetCode 886
class PossibleBipartition_886
{
public:
    /**
     * 本质上就是一个图
     * @param N
     * @param dislikes
     * @return
     */
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        /*
         * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
         * Output: false
         */
        if (N <= 2)
            return true;
        vector<vector<int> > graph(N + 1);
        for (auto pair : dislikes)
        {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        vector<int> group(N + 1);

        for(int i = 1; i < group.size(); i++)
        {
            if(group[i] != 0)
                continue;
            group[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int point = q.front();
                q.pop();
                for (auto neighbor : graph[point])
                {
                    if (group[neighbor] == 0)
                    {
                        group[neighbor] = 3 - group[point];
                        q.push(neighbor);
                    }
                    else if (group[neighbor] == group[point])
                        return false;
                }
            }
        }
        return true;
    }
};

#endif //LEETCODECPP_POSSIBLEBIPARTITION_H
