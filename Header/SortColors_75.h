//
// Created by lidong on 2020/6/12.
//

#ifndef LEETCODECPP_SORTCOLORS_75_H
#define LEETCODECPP_SORTCOLORS_75_H

#include <vector>

using namespace std;

class SortColors_75
{
public:
    void sortColors(vector<int> &nums)
    {
        //    vector<int> nums4{2,2,0,1,1,0,0,1,2,2,1,1};
        int whiteIndex = -1, blueIndex = -1;
        for (decltype(nums.size()) i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (i > whiteIndex && whiteIndex >= 0)
                {
                    mySwap(nums[i], nums[whiteIndex]);
                    if (whiteIndex + 1 < nums.size())
                    {
                        if (nums[whiteIndex + 1] != 1)
                            whiteIndex = i;
                        else
                            whiteIndex++;
                    }
                }
                else if (i > blueIndex && blueIndex >= 0)
                {

                    mySwap(nums[i], nums[blueIndex]);
                    if (blueIndex + 1 < nums.size())
                    {
                        if (nums[blueIndex + 1] != 2)
                            blueIndex = i;
                        else
                            blueIndex++;
                    }
                }
            }
            if (nums[i] == 1)
            {
                if (whiteIndex < 0)
                    whiteIndex = i;
                if (i > blueIndex && blueIndex >= 0)
                {
                    mySwap(nums[i], nums[blueIndex]);
                    if (whiteIndex == i)
                        whiteIndex = blueIndex;
                    if (blueIndex + 1 < nums.size())
                    {
                        if (nums[blueIndex + 1] != 2)
                            blueIndex = i;
                        else
                            blueIndex++;
                    }
                }
            }
            else if (nums[i] == 2)
            {
                if (blueIndex < 0)
                    blueIndex = i;
            }
        }
    }

    void mySwap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    //一种简洁的做法
    void sortColors2(vector<int> &nums)
    {
        unsigned int l = 0, mid = 0, h = nums.size() - 1;
        while (mid <= h)
        {
            if (nums[mid] == 0)
                swap(nums[mid++], nums[l++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[h--]);
        }
    }
};


#endif //LEETCODECPP_SORTCOLORS_75_H
