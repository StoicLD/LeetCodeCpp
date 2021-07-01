//
// Created by lidong on 2021/6/26.
//

#ifndef LEETCODECPP_COUNTOFSMALLERNUMBERSAFTERSELF_315_H
#define LEETCODECPP_COUNTOFSMALLERNUMBERSAFTERSELF_315_H

#include <stack>

class Count_Of_Smaller_Numbers_After_Self_315 {
public:

    struct TreeNode
    {
        int val;
        int left_num = 0;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr)
        {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr)
        {}

        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
        {}
    };

    /**
     * @brief 使用插入排序的一种解法，复杂度应该是在O(n) -> O(n^2)
     * @param nums
     * @return
     */
    std::vector<int> countSmaller(std::vector<int>& nums)
    {
        std::vector<int> count_vec(nums.size(), 0);
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[j - 1] > nums[j])
                {
                    count_vec[i] = nums.size() - j;
                    break;
                }
                else
                {
                    std::swap(nums[j - 1], nums[j]);
                }
            }
        }
        return count_vec;
    }

    /**
     * @brief 构建一颗BST，复杂度应该是在O(nlogn) -> O(n^2)
     * @param nums
     * @return
     */
    std::vector<int> countSmaller2(std::vector<int>& nums)
    {
        std::vector<int> count_vec(nums.size(), 0);
        TreeNode root;
        root.val = nums[nums.size() - 1];
        root.left_num = 0;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            TreeNode* curr_node = &root;
            while (curr_node)
            {
                if (curr_node->val >= nums[i])
                {
                    curr_node->left_num += 1;
                    if(curr_node->left)
                    {
                        curr_node = curr_node->left;
                        continue;
                    }
                    else
                    {
                        curr_node->left = new TreeNode(nums[i]);
                        break;
                    }
                }
                else
                {
                    count_vec[i] += curr_node->left_num + 1;
                    if(curr_node->right)
                    {
                        curr_node = curr_node->right;
                        continue;
                    }
                    else
                    {
                        curr_node->right = new TreeNode(nums[i]);
                        break;
                    }
                }
            }
        }

        return count_vec;
    }

    TreeNode* countSmaller2Helper(std::vector<int>& nums, std::vector<int>& count_vec, TreeNode* node, int index)
    {
        if (!node)
        {
            return new TreeNode(nums[index]);
        }
        if (node->val >= nums[index])
        {
            node->left = countSmaller2Helper(nums, count_vec, node->left, index);
            return node->left;
        }
        else
        {
            count_vec[index] += 1;
            node->right = countSmaller2Helper(nums, count_vec, node->right, index);
            return node->right;
        }
    }
};

#endif //LEETCODECPP_COUNTOFSMALLERNUMBERSAFTERSELF_315_H
