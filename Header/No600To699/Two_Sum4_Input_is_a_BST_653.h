//
// Created by Dong Li on 8/23/21.
//

#ifndef LEETCODECPP_HEADER_NO600TO699_TWO_SUM4_INPUT_IS_A_BST_653_H_
#define LEETCODECPP_HEADER_NO600TO699_TWO_SUM4_INPUT_IS_A_BST_653_H_
#include <vector>
#include <stack>
#include "Utils/TreeNode.h"
using namespace std;

class Two_Sum4_Input_is_a_BST_653 {
public:

    void inorderTravel(vector<int>& bst_vec, TreeNode* root)
    {
        stack<TreeNode*> bst_stack;
        auto curr_node = root;
        while (curr_node || !bst_stack.empty())
        {
            if(curr_node)
            {
                bst_stack.push(curr_node);
                curr_node = curr_node->left;
            }
            else
            {
                auto node = bst_stack.top();
                bst_stack.pop();
                bst_vec.push_back(node->val);
                curr_node = node->right;
            }
        }
    }

    /**
     * 一种O(N2)的解法
     * @param root
     * @param k
     * @return
     */
    bool findTarget(TreeNode* root, int k) {
        vector<int> bst_vec;
        inorderTravel(bst_vec, root);

        // 到这里得到了完整的排好序的数组
        for(int i = 0; i < bst_vec.size() - 1; i++)
        {
            for(int j = i + 1; j < bst_vec.size(); j++)
            {
                if(bst_vec[i] + bst_vec[j] == k)
                {
                    return true;
                }
                else if(bst_vec[i] + bst_vec[j] > k)
                {
                    break;
                }
            }
        }
        return false;
    }


    /**
     * 一种O(N)的解法，采用双指针法，双指针一个从头部节点开始，一个从尾部节点开始
     * @param root
     * @param k
     * @return
     */
    bool findTarget2(TreeNode* root, int k) {
        vector<int> bst_vec;
        inorderTravel(bst_vec, root);
        for(int i = 0, j = bst_vec.size() - 1; i < j;)
        {
            if(bst_vec[i] + bst_vec[j] == k)
            {
                return true;
            }
            else if(bst_vec[i] + bst_vec[j] > k)
            {
                // 当两指针的和大于目标的时候，右指针递减
                // 因为任意的左指针以右的节点都大于当前左指针，他们与当前右指针的和肯定是更大的
                // 所以递减右指针，相反的情况同理
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }


};
#endif //LEETCODECPP_HEADER_NO600TO699_TWO_SUM4_INPUT_IS_A_BST_653_H_
