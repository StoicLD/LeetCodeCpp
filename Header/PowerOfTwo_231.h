//
// Created by lidong on 2020/6/9.
//

#ifndef LEETCODECPP_POWEROFTWO_231_H
#define LEETCODECPP_POWEROFTWO_231_H
#include <vector>
using namespace std;
class PowerOfTwo_231
{
public:
    /**
     * O(logN)的解法
     * @param n
     * @return
     */
    bool isPowerOfTwo(int n)
    {
        int num = 0;
        while (n > 0)
        {
            num += ((n & 1) == 1) ? 1 : 0;
            n >>= 1;
        }
        return num == 1;
    }

    /**
     * O(1)的解法
     * @param n
     * @return
     */
    bool isPowerOfTwo2(int n)
    {
        if(n<=0)
            return false;
        return !(n&(n-1));
    }
};

#endif //LEETCODECPP_POWEROFTWO_231_H
