//
// Created by Dong Li on 9/4/21.
//

#ifndef LEETCODECPP_HEADER_NO100TO199_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_102_H_
#define LEETCODECPP_HEADER_NO100TO199_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_102_H_

#include <queue>
#include <vector>
#include "Utils/TreeNode.h"

class Binary_Tree_Level_Order_Traversal_102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
        {
            return result;
        }
        vector<queue<TreeNode*>> node_queues;
        node_queues.resize(2);
        int curr_index = 0;
        int level = 0;
        node_queues[curr_index].push(root);
        while(!node_queues[curr_index].empty())
        {
            auto node = node_queues[curr_index].front();
            if(node)
            {
                if(result.size() < level + 1)
                {
                    result.push_back(vector<int>());
                }
                result[level].push_back(node->val);
                node_queues[1 - curr_index].push(node->left);
                node_queues[1 - curr_index].push(node->right);
            }
            node_queues[curr_index].pop();
            if(node_queues[curr_index].empty())
            {
                level++;
                curr_index = 1 - curr_index;
            }
        }
        return result;
    }

    /**
     * 只需要一个队列就可以解决，根本不需要两个队列
     * @param root
     * @return
     */
    vector<vector<int>> levelOrder2(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            // 核心在于不是每个节点都进入循环，每次while循环都是一层
            vector<int> vec;
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
#endif //LEETCODECPP_HEADER_NO100TO199_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_102_H_
