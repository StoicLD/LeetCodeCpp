//
// Created by lidong on 2021/4/6.
//

#ifndef LEETCODECPP_MINIMUMOPERATIONSTOMAKEARRAYEQUAL_1551_H
#define LEETCODECPP_MINIMUMOPERATIONSTOMAKEARRAYEQUAL_1551_H
//TODO No.1551
class MinimumOperationsToMakeArrayEqual
{
public:
    int MinOperations(int n) {
        return (n % 2) == 0 ? (n * n / 4) : (n * n - 1) / 4;
    }
};


#endif //LEETCODECPP_MINIMUMOPERATIONSTOMAKEARRAYEQUAL_1551_H
