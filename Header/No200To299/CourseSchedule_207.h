//
// Created by lidong on 2020/5/29.
//

#ifndef LEETCODECPP_COURSESCHEDULE_207_H
#define LEETCODECPP_COURSESCHEDULE_207_H
#include <vector>
#include <map>
#include <stack>
using namespace std;
//TODO LeetCode 207
class CourseSchedule_207
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        if(numCourses <= 1)
            return true;
        //0表示未访问过，1表示已经访问但还有没有访问的节点，2表示已经访问无需在访问
        vector<int> canLearn(numCourses, 0);
        map<int, vector<int> > graphMatrix;
        for(auto vec : prerequisites)
        {
            graphMatrix[vec[0]];
            graphMatrix[vec[0]].push_back(vec[1]);
        }

        // DFS比较好
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(i, canLearn, graphMatrix))
                return false;
        }
        return true;
    }

    bool dfs(int current, vector<int>& canLearn, map<int, vector<int> >& graph)
    {
        if(canLearn[current] == 1)
            return false;
        else if(canLearn[current] == 2)
            return true;

        canLearn[current] = 1;
        for(auto i : graph[current])
        {
            if(!dfs(i, canLearn, graph))
                return false;
        }
        canLearn[current] = 2;
        return true;
    }

};


#endif //LEETCODECPP_COURSESCHEDULE_207_H
