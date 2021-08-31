//
// Created by Dong Li on 8/25/21.
//

#ifndef LEETCODECPP_HEADER_NO600TO699_SUM_OF_SQUARE_NUMBERS_633_H_
#define LEETCODECPP_HEADER_NO600TO699_SUM_OF_SQUARE_NUMBERS_633_H_
using namespace std;
class Sum_of_Square_Numbers_633 {
public:
    bool judgeSquareSum(int c) {
        double sqrt_c = sqrt(c);
        for(int a = 0; a <= (int)sqrt_c; a++)
        {
            int b2 = c - a * a;
            int b = (int)sqrt(c - a * a);
            if(b * b == b2)
            {
                return true;
            }
        }
        return false;
    }
};
#endif //LEETCODECPP_HEADER_NO600TO699_SUM_OF_SQUARE_NUMBERS_633_H_
