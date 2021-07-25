//
// Created by lidong on 2020/6/18.
//

#ifndef LEETCODECPP_HINDEX2_275_H
#define LEETCODECPP_HINDEX2_275_H

#include <vector>
#include <algorithm>
using namespace std;

class HIndex2_275
{
public:
    /*
     * O(N)的暴力做法
     */
    int hIndex(vector<int> &citations)
    {
        // O(log(N))
        // [0,1,1,1,1,2,2,2,2]  = 2
        // [0,1,2,2,3,4,5,12]      = 3
        // [0,0,4,4]
        int n = citations.size();
        while (n > 0)
        {
            if(citations[citations.size() - n] >= n)
                return n;
            n--;
        }
        return n;
    }

    int hIndex2(vector<int> &citations)
    {
        // O(log(N))
        // [0,1,1,1,1,2,2,2,2]  = 2
        // [0,1,2,2,3,4,5,12]   = 3
        // [0,0,4,4]            = 2
        int low = 1;
        int high = citations.size();
        int result = 0;
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            if(citations[citations.size() - mid] >= mid)
            {
                result = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
    }
};


#endif //LEETCODECPP_HINDEX2_275_H
