//
// Created by Dong Li on 9/4/21.
//

#ifndef LEETCODECPP_HEADER_NO800TO899_SUM_OF_DISTANCES_IN_TREE_834_H_
#define LEETCODECPP_HEADER_NO800TO899_SUM_OF_DISTANCES_IN_TREE_834_H_
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Sum_of_Distances_in_Tree_834 {
public:
    /**
     * 超时间的一种解法
     * @param n
     * @param edges
     * @return
     */
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> path_table(n, vector<int>(n, -1));
        vector<unordered_map<int, unordered_set<int>>> length_map(n, unordered_map<int, unordered_set<int>>());
        vector<int> result_table(n, 0);

        for(int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            path_table[a][b] = 1;
            path_table[b][a] = 1;
            length_map[a][1].insert(b);
            length_map[b][1].insert(a);
            result_table[a] += 1;
            result_table[b] += 1;
        }
        
        for(int i = 0; i < n; i++)
        {
            auto& length_map_of_i = length_map[i];
            for(int dis = 1; length_map_of_i.find(dis) != length_map_of_i.end(); dis++)
            {
                for(auto j : length_map_of_i[dis])
                {
                    auto& length_map_of_j =length_map[j];
                    // 长度为dis的点
                    if(length_map_of_j.find(1) != length_map_of_j.end())
                    {
                        // 遍历长度为dis的所有临接点
                        for(auto k : length_map_of_j[1])
                        {
                            if(path_table[i][k] == -1 && i != k)
                            {
                                length_map_of_i[dis + 1].insert(k);
                                path_table[i][k] = dis + 1;
                                result_table[i] += dis + 1;
                                // 是否在这里把对应的另外一个点的数据也更新？
                            }
                        }
                    }
                }
            }
            
        }
        return result_table;
    }


    /**
     * O(n)的一种巧妙做法
     * 该方法的关键是先求出以每个子节点为头节点的子树一共有多少个子节点
     * 以及改子节点到所有自己的子节点的距离和。这能通过一次post-order的遍历解决。随后再通过一次pre-order的遍历更新得到最终的结果
     * count_subtrees[i]表示节点i的子节点个树（包括自己）
     * sum_all[i] 一开始表示节点i到所有自己的子节点的距离之和。后面将会用来表示最终的结果（也就是节点i到所有的其他节点的距离和）
     *
     * 核心方法：
     * 之所以我们可以先求出子树，最最关键的是要看清楚一个性质。
     * 那就是如果已知父节点到所有其他子节点的距离和，假设我们知道节点0到其他所有子节点的距离和是10
     * 那么接下来，0的一个子节点（比如说1）到其他所有节点的距离和可以分为两个部分
     * （1）节点1到自己的子节点的距离和，这个已经通过第一次遍历算出来了，存在sum_all[child]里面
     * （2）节点1到其父节点的所有其他子树包含的节点的距离和。(也就是不包含1所在子树的节点）
     *  该距离就等于 sum_all[parent] - (sum_all[child] + count[child]) + (N - count[i])
     *  具体解释：sum_all[parent]已经是父节点到其他所有节点的距离和了，而(sum_all[child] + count[child])表示父节点到child的所有子节点（包括child）的距离和
     *  两者相减 sum_all[parent] - (sum_all[child] + count[child]) 即parent父节点到除了child所在子树之外的所有节点的距离和
     *  因为parent下沉一次，相当于所有的右侧子树（child节点不在的子树）到一个新的节点child的距离更加远了一步，所以要加 1 * (N - count[i]，
     *  N就是总的节点数。
     *  因此更新完之后就是两者想家
     *  sum_all[parent] - (sum_all[child] + count[child]) + (N - count[i])  +  sum_all[child] = sum_all[parent] - count[child] + N - count[i]
     *          0
     *      /   |    \
     *   1      2     3
     *  / \    /    /   \
     * 4   5  6    7     8
     * @param n
     * @param edges
     * @return
     */
    vector<int> sumOfDistancesInTree2(int n, vector<vector<int>>& edges) {
        tree.clear();
        count_subtrees.clear();
        sum_all.clear();
        tree.resize(n);
        count_subtrees.assign(n, 1);
        sum_all.assign(n, 0);

        for(auto& edge : edges)
        {
            tree[edge[0]].insert(edge[1]);
            tree[edge[1]].insert(edge[0]);
        }

        // 先构建子树和子树路径和
        ConstructSubTreesAndTreeCount(-1, 0);
        CalculateDistance(-1, 0);
        return sum_all;
    }

    void ConstructSubTreesAndTreeCount(int parent, int child)
    {
        // 后续遍历（深度优先DFS）
        for(auto i : tree[child])
        {
            // 确保树的方向性，防止重复遍历
            if(i != parent)
            {
                ConstructSubTreesAndTreeCount(child, i);
                // 当前节点的子节点数量等于每个子节点的子节点数量
                count_subtrees[child] += count_subtrees[i];
                sum_all[child] += sum_all[i] + count_subtrees[i];
            }
        }
    }

    void CalculateDistance(int parent, int child)
    {
        for(auto i : tree[child])
        {
            if(i != parent)
            {
                sum_all[i] = sum_all[child] + count_subtrees.size() - count_subtrees[i] - count_subtrees[i];
                CalculateDistance(child, i);
            }
        }
    }


private:
    vector<unordered_set<int>> tree;        // tree[i] 表示与节点i相连的所有节点
    vector<int> count_subtrees;             // count_subtrees[i] 表示节点i包括自己在内的子树一共有多少个节点
    vector<int> sum_all;                    // sum_all[i] 表示最终结果，也就是从节点i到其他所有节点的距离之和
};
#endif //LEETCODECPP_HEADER_NO800TO899_SUM_OF_DISTANCES_IN_TREE_834_H_
