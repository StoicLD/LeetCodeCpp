//
// Created by lidong on 2020/6/3.
//

#ifndef LEETCODECPP_DELETENODEINALINKEDLIST_237_H
#define LEETCODECPP_DELETENODEINALINKEDLIST_237_H

#include "ListNode.h"
//TODO LeetCode 237
class DeleteNodeInALinkedList_237 {
public:
    void deleteNode(ListNode* node)
    {
        //只给定了要删除的节点，因此采取移动重新赋值的方法
        // 3 -> 4 -> 1 -> 9 -> 2 删除1
        // 因为不知道3，4的信息，所以直接把1之后的节点全部提前（赋值），删除最后一个节点
        ListNode* next = node->next;
        while (next->next != nullptr)
        {
            node->val = next->val;
            node = next;
            next = next->next;
        }
        node->val = next->val;
        node->next = nullptr;
    }

    void deleteNode2(ListNode* node)
    {
        //只需要 O(1)的时间就行了。。只需要交换一个节点
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        next->next = nullptr;
    }
};
#endif //LEETCODECPP_DELETENODEINALINKEDLIST_237_H
