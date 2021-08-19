//
// Created by Dong Li on 8/18/21.
//

#ifndef LEETCODECPP_HEADER_NO1TO99_CLIMBING_STAIRS_70_H_
#define LEETCODECPP_HEADER_NO1TO99_CLIMBING_STAIRS_70_H_
class Climbing_Stairs_70 {
public:
    int climbStairs(int n) {
        if(n <= 2)
        {
            return n;
        }
        int func1 = 1;
        int func2 = 2;

        for(int count = 2; count < n; count++)
        {
            int temp = func2;
            func2 = func1 + func2;
            func1 = temp;
        }
        return func2;
    }
};
#endif //LEETCODECPP_HEADER_NO1TO99_CLIMBING_STAIRS_70_H_
