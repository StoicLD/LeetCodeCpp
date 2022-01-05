//
// Created by Dong Li on 11/20/21.
//

#ifndef LEETCODECPP_HEADER_TIKTOK_TIKTOK_SUMMER_2022_H_
#define LEETCODECPP_HEADER_TIKTOK_TIKTOK_SUMMER_2022_H_
using namespace std;
#include <string>
#include <utility>
class ADTreeNode
{
public:
    int val;
    shared_ptr<ADTreeNode> parent_;
    shared_ptr<ADTreeNode> left_;
    shared_ptr<ADTreeNode> right_;

    ADTreeNode() : val(0), left_(nullptr), right_(nullptr), parent_(nullptr)
    {}

    ADTreeNode(int x) : val(x), left_(nullptr), right_(nullptr), parent_(nullptr)
    {}

    ADTreeNode(int x,
               shared_ptr<ADTreeNode> parent,
               shared_ptr<ADTreeNode> left,
               shared_ptr<ADTreeNode> right)
               : val(x), parent_(std::move(parent)), left_(std::move(left)), right_(std::move(right)) {}
};



class TikTok_Summer_2022
{
public:
    enum TreeError
    {
        E1 = 0,             // more than two children
        E2 = 1,             // Duplicate Edges
        E3 = 2,             // Cycle present
        E4 = 3,             // Multiple roots
        E5 = 4,             // Any other error
        NoError = 5
    };



    TreeError quickUnion(shared_ptr<ADTreeNode> parent, shared_ptr<ADTreeNode> child)
    {
        if(parent->val == child->val)
        {
            return E3;
        }


        return NoError;
    }
    
    shared_ptr<ADTreeNode> quickFind(shared_ptr<ADTreeNode> node) {
        while (node->parent_)
        {
            node = node->parent_;
        }
        return node;
    }
    
    
    
    string GetSmallestSExpression(vector<vector<char>>& input)
    {
        string result = "";
        // (1) construct tree
        


        return result;
    }
};
#endif //LEETCODECPP_HEADER_TIKTOK_TIKTOK_SUMMER_2022_H_
