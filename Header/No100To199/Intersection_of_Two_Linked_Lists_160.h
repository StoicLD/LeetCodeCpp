//
// Created by Dong Li on 8/17/21.
//

#ifndef LEETCODECPP_INTERSECTION_OF_TWO_LINKED_LISTS_160_H
#define LEETCODECPP_INTERSECTION_OF_TWO_LINKED_LISTS_160_H
#include "Utils/ListNode.h"

class Intersection_of_Two_Linked_Lists_160 {
public:
    /**
     * 核心思路在于，两个链表如果相交，那么从相交节点开始的后面部分就是一致的
     * 如下的链表所示，只要保证从相同的长度开始用双指针比较就可以了
     * 1 -> 2 -> 11 -> 3 -> 5
     *      4 -> 11 -> 3 -> 5
     * @param headA
     * @param headB
     * @return
     */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* it_a = headA;
        ListNode* it_b = headB;
        int length_a = 0;
        int length_b = 0;
        while (it_a)
        {
            it_a = it_a->next;
            length_a++;
        }
        while (it_b)
        {
            it_b = it_b->next;
            length_b++;
        }
        it_a = headA;
        it_b = headB;

        while (length_a > length_b)
        {
            it_a = it_a->next;
            length_a--;
        }
        while (length_b > length_a)
        {
            it_b = it_b->next;
            length_b--;
        }

        while (it_a && it_b && it_a != it_b)
        {
            it_a = it_a->next;
            it_b = it_b->next;
        }
        return it_a;
    }
};

#endif //LEETCODECPP_INTERSECTION_OF_TWO_LINKED_LISTS_160_H
