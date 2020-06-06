//
// Created by lidong on 2020/6/6.
//

#ifndef LEETCODECPP_QUEUERECONSTRUCTIONBYHEIGHT_406_H
#define LEETCODECPP_QUEUERECONSTRUCTIONBYHEIGHT_406_H
#include <vector>
#include <algorithm>
using namespace std;
class QueueReconstructionByHeight_408
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        //先建立一个map
        auto comp = [](const vector<int>& p1, const vector<int>& p2)
        { return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); };
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for(auto &p : people)
        {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }

    /**
     * 很nb的想法，先按照first从大大小，second从大到小的顺序排序
     * 然后按照顺序插入就完事了
     * @param people
     * @return
     */
    vector<pair<int, int>> reconstructQueue2(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
        { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> res;

        //比如说 [7,0], [7,1], [6,1], [5,0], [5,2], [4,4] 这个排好序的序列
        //先将[7,0]插入第0个位置，[7,1]插入第1个位置
        //到[6,1]的时候因为前面的都是比它大的，因此只要插入到第1个位置就好了。
        //如此往复即可
        for (auto& p : people)
            res.insert(res.begin() + p.second, p);
        return res;
    }
};


#endif //LEETCODECPP_QUEUERECONSTRUCTIONBYHEIGHT_406_H
