//
// Created by lidong on 2020/6/15.
//

#ifndef LEETCODECPP_CHEAPESTFLIGHTSWITHINKSTOPS_787_H
#define LEETCODECPP_CHEAPESTFLIGHTSWITHINKSTOPS_787_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
//TODO Leetcode 787 Cheapest Flights Within K Stops
typedef tuple<int, int, int> ti;

class CheapestFlightsWithinKStops_787
{
public:
/*    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        //可以直接DFS
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){return a.first < b.first;};
        //先建立一个邻接矩阵
        // scr -> [[dst1, price1], [dst2, price2], [dst3, price3]];
        vector<vector<pair<int, int>>> vecMatrix(n);
        for(auto& vec : flights)
        {
            int index = vec[0];
            vecMatrix[index].emplace_back(vec[1], vec[2]);
        }
        //这个是原始的dijistra priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > pq(cmp);
        //first is the index of start city, second it the acculmate price from source
        pq.push(make_pair(src, 0));
        for(int i = 0; i < n; i++)
        {
            if(i != src)
            {
                pq.push(make_pair(i, numeric_limits<int>::max()));
            }
        }

        // prices[i] = i -> [{2 -> 20}, {3 -> 13}, {1 -> 100}]
        vector<unordered_map<int, int>> prices(n);
        vector<int> nearestPrices(n, numeric_limits<int>::max());
        nearestPrices[src] = 0;

        prices[src].insert(0, 0);

        while (!pq.empty())
        {
            auto topIndex = pq.top().first;
            pq.pop();
            // p_pair = {1, 100} stop = 1, price = 100
            for(auto &p_pair : vecMatrix[topIndex])
            {
                //relax every edge
                for(auto &p_map : prices[p_pair.first])
                {
                    int length = p_map.first;
                    if(length <= K)
                    {
                        prices[length + 1];
                        if(prices[length + 1].)
                    }
                }
            }
        }
    }*/

    /**
     * Dijistra的改变法，把所有的edge都加入进去。
     * @param n
     * @param flights
     * @param src
     * @param dst
     * @param K
     * @return
     */
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<pair<int, int>>> vp(n);
        for (const auto &f:flights) vp[f[0]].emplace_back(f[1], f[2]);
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        pq.emplace(0, src, K + 1);
        while (!pq.empty())
        {
            auto[cost, u, stops] = pq.top();
            pq.pop();
            if (u == dst) return cost;
            if (!stops) continue;
            for (auto to:vp[u])
            {
                auto[v, w] = to;
                pq.emplace(cost + w, v, stops - 1);
            }
        }
        return -1;
    }

    /**
     * DP算法，
     * @param n
     * @param flights
     * @param src
     * @param dst
     * @param K
     * @return
     */
    int findCheapestPriceDP(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // dp[k][v] means the minium cost from src to city v with at most k stops;
        // 开O(k * n)的空间
        vector<vector<int> > dp(K + 2, vector<int>(n, 1e9));
        dp[0][src] = 0;
        for(int i = 1; i <= K + 1; i++)
        {
            dp[i][src] = 0;
            for(auto &e : flights)
            {
                dp[i][e[1]] = min(dp[i][e[1]], dp[i - 1][e[0]] + e[2]);
            }
        }
        return dp[K + 1][dst] >= 1e9 ? -1 : dp[K + 1][dst];
    }
};


#endif //LEETCODECPP_CHEAPESTFLIGHTSWITHINKSTOPS_787_H
