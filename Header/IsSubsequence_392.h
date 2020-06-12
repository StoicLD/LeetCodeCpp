//
// Created by lidong on 2020/6/10.
//

#ifndef LEETCODECPP_ISSUBSEQUENCE_392_H
#define LEETCODECPP_ISSUBSEQUENCE_392_H
#include <string>
using namespace std;
class IsSubsequence_392
{
public:
    bool isSubsequence(string s, string t)
    {
        string::size_type i = 0, j = 0;
        while (i < s.size() && j < t.size())
        {
            if(s.at(i) == t.at(j))
            {
                i++;
                j++;
            }
            else
                j++;
        }
        return i == s.size();
    }
};



#endif //LEETCODECPP_ISSUBSEQUENCE_392_H
