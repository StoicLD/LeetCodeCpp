//
// Created by lidong on 2020/6/1.
//

#ifndef LEETCODECPP_INVERTBINARYTREE_226_H
#define LEETCODECPP_INVERTBINARYTREE_226_H
//TODO LeetCode 226
#include "TreeNode.h"
#include <queue>
using namespace std;
class InvertBinaryTree_226
{
public:
    /**
     * 递归的解法1
     * @param root
     * @return
     */
    TreeNode* invertTree(TreeNode* root)
    {
        if(root == nullptr)
            return root;
        TreeNode* tempLeft = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tempLeft);
        return root;
    }

    /**
     * 迭代循环的版本
     * @param root
     * @return
     */
    TreeNode* invertTree2(TreeNode* root)
    {
        if(root == nullptr)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* tempLeft = node->left;
            node->left = node->right;
            node->right = tempLeft;
            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
        }
        return root;
    }
};


#endif //LEETCODECPP_INVERTBINARYTREE_226_H
