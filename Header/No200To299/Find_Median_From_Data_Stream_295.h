//
// Created by lidong on 2021/7/12.
//

#ifndef LEETCODECPP_FIND_MEDIAN_FROM_DATA_STREAM_295_H
#define LEETCODECPP_FIND_MEDIAN_FROM_DATA_STREAM_295_H

struct TreeNode
{
    int val_;
    int left_num_;
    int right_num_;

    TreeNode* left_;
    TreeNode* right_;

    TreeNode() : val_(0), left_num_(0), right_num_(0), left_(nullptr), right_(nullptr)
    {}

    TreeNode(int x) : val_(x), left_num_(0), right_num_(0), left_(nullptr), right_(nullptr)
    {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val_(x), left_(left), right_(right)
    {
        if(left) {
            left_num_ = 1 + left->left_num_ + left->right_num_;
        }
        if(right) {
            right_num_ = 1 + right->left_num_ + left->right_num_;
        }
    }
};

class MedianFinder
{
public:
    // 第一种做法是直接构造一棵AVL树

    /** initialize your data structure here. */
    MedianFinder()
    {
        root_ = nullptr;
    }

    virtual ~MedianFinder() {
//        TreeNode* curr_node = root_;
//        while (curr_node) {
//
//        }
    }

    void addNum(int num)
    {
        if(!root_)
        {
            root_ = new TreeNode(num);
        }
        else
        {

        }
    }

    double findMedian() {

    }

private:
    TreeNode* root_;
};


class Find_Median_From_Data_Stream_295
{
public:
};


#endif //LEETCODECPP_FIND_MEDIAN_FROM_DATA_STREAM_295_H
