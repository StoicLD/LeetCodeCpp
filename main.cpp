#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        //(1) Construct a DAG
        vector<vector<int> > graph(numCourses, vector<int>(numCourses, 0));
        vector<int> degree(numCourses, 0);
        for(auto& it : prerequisites)
        {
            graph[it[1]][it[0]] += 1;
            degree[it[0]]++;
        }

        //(2) topological sort
        vector<int> result;
        list<int> tmp_list;

        for(int i = 0; i < graph.size(); i++)
        {
            if(degree[i] == 0)
            {
                for(auto child : graph[i])
                {
                    degree[child]--;
                    if(degree[child] == 0)
                    {
                        tmp_list.push_back(child);
                    }
                }
                // graph.erase(it.first);
                result.push_back(i);
            }
        }
        while(!tmp_list.empty())
        {
            int next_course = tmp_list.front();
            tmp_list.pop_front();
            result.push_back(next_course);
            for(auto it : graph[next_course])
            {
                degree[it]--;
                if(degree[it] == 0)
                {
                    tmp_list.push_back(it);
                }
            }
        }

        return result.size() == numCourses ? result : vector<int>{};
    }
};
/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
int main()
{
    FileSystem f;
    f.ls("/");
    f.mkdir("/goowmfn");
    f.ls("/goowmfn");
    f.ls("/goowmfn");
    f.mkdir("/z");
    f.ls("/z");
    f.ls("/z");
    f.addContentToFile("/goowmfn/c", "shetopcy");\
    f.ls("/z");
    auto result = f.ls("/goowmfn/c");
    f.ls("/goowmfn");

    for(auto it : result)
    {
        cout << it << endl;
    }

//    ["FileSystem","mkdir","ls","ls","mkdir","ls","ls","addContentToFile","ls","ls","ls"]
//    [[],["/goowmfn"],["/goowmfn"],["/"],["/z"],["/"],["/"],["/goowmfn/c","shetopcy"],["/z"],["/goowmfn/c"],["/goowmfn"]]
}
