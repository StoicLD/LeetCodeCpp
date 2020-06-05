//
// Created by lidong on 2020/6/5.
//

#ifndef LEETCODECPP_REVERSESTRING_344_H
#define LEETCODECPP_REVERSESTRING_344_H
#include <vector>
using namespace std;
class ReverseString_344
{
public:
    void reverseString(vector<char> &s)
    {
        for(int i = 0; i < s.size() / 2; i++)
        {
            char temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
    }
};


#endif //LEETCODECPP_REVERSESTRING_344_H
