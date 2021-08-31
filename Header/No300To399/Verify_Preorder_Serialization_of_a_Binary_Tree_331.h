//
// Created by Dong Li on 8/26/21.
//

#ifndef LEETCODECPP_HEADER_NO300TO399_VERIFY_PREORDER_SERIALIZATION_OF_A_BINARY_TREE_331_H_
#define LEETCODECPP_HEADER_NO300TO399_VERIFY_PREORDER_SERIALIZATION_OF_A_BINARY_TREE_331_H_
#include <stack>

using namespace std;
class Verify_Preorder_Serialization_of_a_Binary_Tree_331 {
public:
    /**
     * 解放一，根据出入度计算
     * 如果是一个正常的树，头节点会提供两个出度，没有入度
     * 其他非空节点都会提供两个出度，一个入度
     * 空节点提供一个入度。如果出度是+1，入度是-1
     * 那么一颗正常的树累加起来应该是0。无论是in-order还是pre-order还是post-order
     * 只要累加起来是0就一定是一颗正常的二叉树（符合题目定义的，因为题目提供了空节点）
     * 这应该是一个充要条件，具体可能要去看图论的一些基本证明部分
     * @param preorder
     * @return
     */
    bool isValidSerialization(string preorder) {
        if(preorder[0] == '#')
        {
            return preorder.length() <= 1;
        }
        int degree = 2;
        for(int i = 1; i < preorder.length(); i++)
        {
            if(preorder[i] == ',')
            {
                continue;
            }
            else if(preorder[i] != '#')
            {
                degree += 1;
            }
            else
            {
                degree -= 1;
            }
            if(degree <= 0 && i < preorder.length() - 1)
            {
                // 入度永远不可能大于出度
                // 除非遍历到最后一个节点，否则中间过程中不会出现入度大于等于出度的情况
                // 如果入度等于出度了，说明这棵树应该刚刚好构造完成了，否则总会有剩余的待填充节点的
                return false;
            }
            while (i < preorder.length() && preorder[i] != ',')
            {
                i++;
            }
        }
        return degree == 0;
    }
};


#endif //LEETCODECPP_HEADER_NO300TO399_VERIFY_PREORDER_SERIALIZATION_OF_A_BINARY_TREE_331_H_
