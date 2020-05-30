//
// Created by lidong on 2020/5/30.
//

#ifndef LEETCODECPP_KCLOSESTPOINTSTOORIGIN_H
#define LEETCODECPP_KCLOSESTPOINTSTOORIGIN_H

#include <vector>
#include <algorithm>

using namespace std;

class KClosestPointsToOrigin_973
{
public:
    struct Compare
    {
        bool operator()(const vector<int> &aVec, const vector<int> &bVec)
        {
            int aVal = aVec[0] * aVec[0] + aVec[1] * aVec[1];
            int bVal = bVec[0] * bVec[0] + bVec[1] * bVec[1];
            return aVal < bVal;
        }
    } myCompare;

    int square(const vector<int> &vec)
    {
        return vec[0] * vec[0] + vec[1] * vec[1];
    }

    /**
     * 基本正确，只有在两个vector距离相等的时候的顺序不一定稳定
     * @param points
     * @param K
     * @return
     */
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        if (points.empty() || K <= 0)
            return vector<vector<int>>();

        make_heap(points.begin(), points.end(), myCompare);

        vector<vector<int>> result;
        while (K > 0 && !points.empty())
        {
            result.push_back(points.front());
            K--;
            pop_heap(points.begin(), points.end());
            points.pop_back();
            make_heap(points.begin(), points.end(), myCompare);
        }
/*
        int closetVal = square(points.front());
        while (!points.empty())
        {
            if(closetVal == square(points.front()))
            {
                result.push_back(points.front());
            }
            else
                break;
            pop_heap(points.begin(), points.end());
            points.pop_back();
            make_heap(points.begin(), points.end(), myCompare);
        }*/
        return result;
    }

    /**
     * 使用内置函数
     * @param points
     * @param K
     * @return
     */
    vector<vector<int>> kClosest2(vector<vector<int>> &points, int K)
    {
        nth_element(points.begin(), points.begin() + K - 1, points.end(), [](vector<int> &p, vector<int> &q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }

    /**
     * QuickSelect方法，类似于快排，CS61B的最后几个discussion中有讨论
     * @param points
     * @param K
     * @return
     */
    vector<vector<int>> kClosest3(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        while (true) {
            int p = partition(points, l, r);
            if (p == K - 1) {
                break;
            }
            if (p < K - 1) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
private:
    bool farther(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
    }

    bool closer(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = left, l = left + 1, r = right;
        while (l <= r) {
            if (farther(points[l], points[pivot]) && closer(points[r], points[pivot])) {
                swap(points[l++], points[r--]);
            }
            if (!farther(points[l], points[pivot])) {
                l++;
            }
            if (!closer(points[r], points[pivot])) {
                r--;
            }
        }
        swap(points[pivot], points[r]);
        return r;
    }

};

#endif //LEETCODECPP_KCLOSESTPOINTSTOORIGIN_H
