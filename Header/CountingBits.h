//
// Created by lidong on 2020/5/28.
//

#ifndef LEETCODECPP_COUNTINGBITS_H
#define LEETCODECPP_COUNTINGBITS_H

#include <vector>

using namespace std;

class CountingBits_338
{
public:
    vector<int> countBits(int num)
    {
        if (num == 0)
            return vector<int>{0};
        vector<int> result(num + 1);
        int collective = 1;
        result[1] = 1;
        for (int i = 2; i <= num; i++)
        {
            if (i == collective * 2)
            {
                collective *= 2;
                result[i] = 1;
            }
            else
            {
                result[i] = result[i - collective] + 1;
            }
        }
        return result;
    }

    /**
     * 位与操作
     * 1110 & 1101 = 1100
     * 10000 & 01111 = 00000
     * @param num
     * @return
     */
    vector<int> countBits2(int num)
    {
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i & (i - 1)] + 1;
        return ret;
    }
};

#endif //LEETCODECPP_COUNTINGBITS_H
