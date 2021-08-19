//
// Created by Dong Li on 8/18/21.
//

#ifndef LEETCODECPP_HEADER_NO100TO199_LINKED_LIST_CYCLE2_142_H_
#define LEETCODECPP_HEADER_NO100TO199_LINKED_LIST_CYCLE2_142_H_
#include "Utils/ListNode.h"
class Linked_List_Cycle2_142 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};







#endif //LEETCODECPP_HEADER_NO100TO199_LINKED_LIST_CYCLE2_142_H_
