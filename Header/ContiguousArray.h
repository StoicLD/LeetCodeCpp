//
// Created by lidong on 2020/5/27.
//

#ifndef LEETCODECPP_CONTIGUOUSARRAY_H
#define LEETCODECPP_CONTIGUOUSARRAY_H
#include <vector>
#include <map>
#include <algorithm>
class ContiguousArray_525
{
public:
    int findMaxLength(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        //vector<int> dp(nums.size());
        std::map<int, int> dp;
        dp.insert(std::make_pair(0, -1));
        int result = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i] == 0 ? -1 : 1;
            if (dp.find(count) != dp.end())
            {
                result = std::max(result, i - dp.at(count));
            }
            else
            {
                dp.insert(std::make_pair(count, i));
            }
        }
        return result;
    }
};

#endif //LEETCODECPP_CONTIGUOUSARRAY_H
