//
// Created by Dong Li on 11/7/21.
//

#ifndef LEETCODECPP_HEADER_NO200TO299_LEETCODE_239_H_
#define LEETCODECPP_HEADER_NO200TO299_LEETCODE_239_H_
#include <vector>
#include <queue>
using namespace std;
class LeetCode_239
{
public:
    // use a priority queue and hashtable
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> table;
        // int curr_max = nums[0];
        // std::priority_queue<int> pq;
        int start = 0, end = k - 1;
        std::priority_queue<int, std::vector<int>, std::less<>> pq;
        for(int i = 0; i <= end; i++)
        {
            pq.push(nums[i]);
        }

        while(1)
        {
            // select max
            result.push_back(pq.top());

            // move window
            if(end + 1 < nums.size())
            {
                int top_val = pq.top();
                if(top_val != nums[start])
                {
                    table[nums[start]] += 1;
                }
                else
                {
                    pq.pop();
                    while(!pq.empty() && table.find(pq.top()) != table.end() && table[pq.top()] > 0)
                    {
                        table[pq.top()]--;
                        pq.pop();
                    }

                }
                pq.push(nums[end + 1]);
            }
            else
            {
                break;
            }

            end++;
            start++;
        }

        return result;
    }
};


#endif //LEETCODECPP_HEADER_NO200TO299_LEETCODE_239_H_
