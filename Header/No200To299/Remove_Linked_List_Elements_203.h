//
// Created by lidong on 2021/7/22.
//

#ifndef LEETCODECPP_REMOVE_LINKED_LIST_ELEMENTS_203_H
#define LEETCODECPP_REMOVE_LINKED_LIST_ELEMENTS_203_H
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode next) : val(x), next(next) {}
};

class Remove_Linked_List_Elements_203
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        auto result_head = head;
        while (result_head != nullptr && result_head->val == val)
        {
            auto tmp = result_head;
            result_head = result_head->next;
            delete tmp;
        }
        auto pre_node = result_head;
        auto next_node = result_head == nullptr ? nullptr : result_head->next;
        while (next_node != nullptr)
        {
            if(next_node->val == val)
            {
                pre_node->next = next_node->next;
            }
            else
            {
                pre_node = next_node;
            }
            next_node = next_node->next;
        }
        return result_head;
    }
};
#endif //LEETCODECPP_REMOVE_LINKED_LIST_ELEMENTS_203_H
