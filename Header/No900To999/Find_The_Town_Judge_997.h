//
// Created by lidong on 2021/7/1.
//

#ifndef LEETCODECPP_FIND_THE_TOWN_JUDGE_997_H
#define LEETCODECPP_FIND_THE_TOWN_JUDGE_997_H
using namespace std;
#include <map>
class Find_The_Town_Judge_97{
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1 && trust.empty())
            return 1;
        std::map<int,int> potenial_judges;
        int max_trustee = 0;
        int judge = -1;
        for(auto it : trust) {
            potenial_judges[it[1]];
            potenial_judges[it[0]] = -1;
            if(potenial_judges[it[1]] != -1)
            {
                potenial_judges[it[1]] += 1;
            }
            if(max_trustee < potenial_judges[it[1]] && potenial_judges[it[1]] != -1) {
                max_trustee = potenial_judges[it[1]];
                judge = it[1];
            }
        }
        return (judge != -1 && potenial_judges[judge] == (n - 1)) ? judge : -1;
    }

};

#endif //LEETCODECPP_FIND_THE_TOWN_JUDGE_997_H
