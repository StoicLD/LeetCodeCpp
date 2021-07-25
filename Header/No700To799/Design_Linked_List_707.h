//
// Created by lidong on 2021/7/22.
//

#ifndef LEETCODECPP_DESIGN_LINKED_LIST_707_H
#define LEETCODECPP_DESIGN_LINKED_LIST_707_H

#include <map>

using namespace std;

class MyLinkedList
{
public:
    struct ListNode
    {
        int val_;
        ListNode *next_;
        ListNode *pre_;

        ListNode() : val_(0), next_(nullptr), pre_(nullptr)
        {}

        ListNode(int x) : val_(x), next_(nullptr), pre_(nullptr)
        {}

        ListNode(int x, ListNode* next, ListNode* pre) : val_(x), next_(next), pre_(pre)
        {}
    };

    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head_ = new ListNode(-1);
        tail_ = new ListNode(-1);
        list_size_ = 0;
        head_->next_ = tail_;
        tail_->pre_ = head_;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if(index < 0 || index >= list_size_)
            return -1;
        auto node = head_->next_;
        int count = 0;
        while (node && count < index)
        {
            node = node->next_;
            count++;
        }
        return node ? node->val_ : -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        auto node = new ListNode(val);
        auto temp_node = head_->next_;
        head_->next_ = node;
        node->pre_ = head_;
        node->next_ = temp_node;
        temp_node->pre_ = node;
        list_size_++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        auto node = new ListNode(val);
        auto temp_node = tail_->pre_;
        node->next_ = tail_;
        node->pre_ = temp_node;
        tail_->pre_ = node;
        temp_node->next_ = node;
        list_size_++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if(index < 0 || index > list_size_)
            return;
        auto new_node = new ListNode(val);
        auto node = head_->next_;
        int count = 0;
        while (node && count < index)
        {
            node = node->next_;
            count++;
        }
        auto pre_node = node->pre_;
        pre_node->next_ = new_node;
        new_node->next_ = node;
        new_node->pre_ = pre_node;
        node->pre_ = new_node;
        list_size_++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if(index < 0 || index >= list_size_)
            return;
        auto node = head_->next_;
        int count = 0;
        while (node && count < index)
        {
            node = node->next_;
            count++;
        }
        auto pre_node = node->pre_;
        auto next_node = node->next_;
        pre_node->next_ = next_node;
        next_node->pre_ = pre_node;
        list_size_--;
        delete node;
    }

private:
    ListNode* head_;
    ListNode* tail_;
    size_t list_size_;
};

#endif //LEETCODECPP_DESIGN_LINKED_LIST_707_H
