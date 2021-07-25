//
// Created by lidong on 2020/5/31.
//

#ifndef LEETCODECPP_EDITDISTANCE_72_H
#define LEETCODECPP_EDITDISTANCE_72_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//TODO LeetCode 72
class EditDistance_72
{
public:
    // 先找到最大公共子串
    // 同时记录位置，随后
    /*int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> cur(n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            cur[j] = j;
        }
        for (int i = 1; i <= m; i++)
        {
            pre = cur[0];
            cur[0] = i;
            for (int j = 1; j <= n; j++)
            {
                int temp = cur[j];
                if (word1[i - 1] == word2[j - 1])
                {
                    cur[j] = pre;
                }
                else
                {
                    cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
                }
                pre = temp;
            }
        }
        return cur[n];
    }*/


    /**
     * 正常做法。。。。DP的做法
     * @param word1
     * @param word2
     * @return
     */
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> cur(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cur[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            pre = cur[0];
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = cur[j];
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre;
                } else {
                    cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};


#endif //LEETCODECPP_EDITDISTANCE_72_H
