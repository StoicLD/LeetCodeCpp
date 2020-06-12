//
// Created by lidong on 2020/6/11.
//

#ifndef LEETCODECPP_SEARCHINSERTPOSITION_35_H
#define LEETCODECPP_SEARCHINSERTPOSITION_35_H
#include <vector>
using namespace std;
//TODO Leetcode 35
class SearchInsertPosition_35
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        // 1,3,5,6         2
        int i = 0;
        for(; i < nums.size();)
        {
            if(nums[i] < target)
                i++;
            else
                break;
        }
        return i;
    }
};


#endif //LEETCODECPP_SEARCHINSERTPOSITION_35_H
