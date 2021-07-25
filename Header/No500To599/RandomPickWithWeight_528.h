//
// Created by lidong on 2020/6/6.
//

#ifndef LEETCODECPP_RANDOMPICKWITHWEIGHT_528_H
#define LEETCODECPP_RANDOMPICKWITHWEIGHT_528_H
#include <vector>
#include <map>
#include <cstdlib>
#include <random>
using namespace std;
class RandomPickWithWeight_528
{
public:
    vector<pair<int, int>> disVec;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;

    RandomPickWithWeight_528(vector<int>& w)
    {
        int lowerBound = 1;
        for(int i = 0; i < w.size(); i++)
        {
            disVec.emplace_back(lowerBound, lowerBound + w[i] - 1);
            lowerBound += w[i];
        }
        random_device rd;
        gen = mt19937(rd());
        dis = uniform_int_distribution<>(1, lowerBound - 1);
    }

    int pickIndex()
    {
        int number = dis(gen);
        int low = 0, high = disVec.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if(disVec[mid].first <= number && disVec[mid].second >= number)
            {
                //find the number in that index
                return mid;
            }
            if(number < disVec[mid].first)
            {
                high = mid - 1;
            }
            else if(number > disVec[mid].second)
            {
                low = mid + 1;
            }
        }
        //理论上不应该到这里
        return -1;
    }
};

#endif //LEETCODECPP_RANDOMPICKWITHWEIGHT_528_H
