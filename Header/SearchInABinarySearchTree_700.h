//
// Created by lidong on 2020/6/16.
//

#ifndef LEETCODECPP_SEARCHINABINARYSEARCHTREE_700_H
#define LEETCODECPP_SEARCHINABINARYSEARCHTREE_700_H
#include <vector>
#include "TreeNode.h"
using namespace std;
//TODO Leetcode 700
class SearchInABinarySearchTree_700
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if(root == nullptr)
            return root;
        if(root->val == val)
            return root;
        else
            return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }

    TreeNode* searchBST2(TreeNode* root, int val)
    {
        TreeNode* ptr = root;
        while (ptr != nullptr && ptr->val != val)
        {
            if(ptr->val > val)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        return ptr;
    }
};


#endif //LEETCODECPP_SEARCHINABINARYSEARCHTREE_700_H
