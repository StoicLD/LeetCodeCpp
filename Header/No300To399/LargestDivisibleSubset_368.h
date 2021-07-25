//
// Created by lidong on 2020/6/14.
//

#ifndef LEETCODECPP_LARGESTDIVISIBLESUBSET_368_H
#define LEETCODECPP_LARGESTDIVISIBLESUBSET_368_H
#include <vector>
#include <algorithm>
using namespace std;
class LargestDivisibleSubset_368
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        vector<int> subSets(nums.size());  // count[n] 表示以nums[n]为最大元素的最大subset的长度
        vector<int> pre(nums.size());    // pre[n] 表示nums[n]在包含它的最大subset中的上一个元素的index
        sort(nums.begin(), nums.end());

        int largestEndIndex = 0;
        int maxCount = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            subSets[i] = 1;
            pre[i] = -1;
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0 && subSets[i] < subSets[j] + 1)
                {
                    subSets[i] = subSets[j] + 1;
                    pre[i] = j;
                }
            }
            if(maxCount < subSets[i])
            {
                maxCount = subSets[i];
                largestEndIndex = i;
            }
        }

        //构建最大subset
        vector<int> result(maxCount);
        for(int i = largestEndIndex, j = maxCount - 1; i >= 0 && j >= 0; i = pre[i], j--)
        {
            result[j] = nums[i];
        }
        return result;
    }
};


#endif //LEETCODECPP_LARGESTDIVISIBLESUBSET_368_H
