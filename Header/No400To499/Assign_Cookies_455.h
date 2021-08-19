//
// Created by Dong Li on 8/18/21.
//

#ifndef LEETCODECPP_HEADER_NO400TO499_ASSIGN_COOKIES_455_H_
#define LEETCODECPP_HEADER_NO400TO499_ASSIGN_COOKIES_455_H_
using namespace std;
class Assign_Cookies_455 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int result = 0;
        for(int i = 0, j = 0; i < g.size() && j < s.size(); i++)
        {
            while (j < s.size())
            {
                if(s[j] >= g[i])
                {
                    result++;
                    j++;
                    break;
                }
                j++;
            }
        }
        return result;
    }
};

#endif //LEETCODECPP_HEADER_NO400TO499_ASSIGN_COOKIES_455_H_
