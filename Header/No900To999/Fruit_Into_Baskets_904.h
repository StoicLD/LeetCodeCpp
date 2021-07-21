//
// Created by lidong on 2021/7/21.
//

#ifndef LEETCODECPP_FRUIT_INTO_BASKETS_904_H
#define LEETCODECPP_FRUIT_INTO_BASKETS_904_H

#include <set>
using namespace std;
class Fruit_Into_Baskets_904
{
public:

    bool needStop(int fruits_type, std::set<int> picked_tree_types)
    {
        return (picked_tree_types.find(fruits_type) == picked_tree_types.end() && picked_tree_types.size() == 2);
    }

    /**
     * @brief 滑动窗口的解法，耗时o(n)
     * @param fruits
     * @return
     */
    int totalFruit(std::vector<int> &fruits)
    {
        int max_pick_trees = 0;
        int start_window = 0;
        std::set<int> picked_tree_types;
        for (int end_window = 0; end_window < fruits.size(); end_window++)
        {
            if (needStop(fruits[end_window], picked_tree_types))
            {
                picked_tree_types.clear();
                start_window = end_window;
                picked_tree_types.insert(fruits[start_window - 1]);
            }
            else
            {
                max_pick_trees = std::max(max_pick_trees, end_window - start_window + 1);
            }
            picked_tree_types.insert(fruits[end_window]);
            while (start_window - 1 < fruits.size() && !needStop(fruits[start_window - 1], picked_tree_types))
            {
                start_window--;
            }
        }
        return max_pick_trees;
    }

    /**
     * @brief 别人的快速解法，也是滑动窗口
     * @param tree
     * @return
     */
    int totalFruit2(vector<int>& tree) {
        unordered_map<int, int> basket;
        int result = 0, len = 0;
        int left = 0;
        for (int i = 0; i < tree.size(); i++) {
            basket[tree[i]]++;
            len++;
            while (basket.size() > 2) {
                basket[tree[left]]--;
                if (basket[tree[left]] == 0) basket.erase(tree[left]);
                left++;
                len--;
            }
            if (result < len) {
                result = len;
            }
        }
        return result;
    }

};

#endif //LEETCODECPP_FRUIT_INTO_BASKETS_904_H
