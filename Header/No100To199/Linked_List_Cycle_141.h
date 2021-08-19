//
// Created by Dong Li on 8/17/21.
//

#ifndef LEETCODECPP_HEADER_NO100TO199_LINKED_LIST_CYCLE_141_H_
#define LEETCODECPP_HEADER_NO100TO199_LINKED_LIST_CYCLE_141_H_
#include "Utils/ListNode.h"

class Linked_List_Cycle_141{
public:
    /**
     * 如果相遇一定是在环中相遇，使用快慢指针法
     * @param head
     * @return
     */
    bool hasCycle(ListNode *head)
    {
        if(!head)
        {
            return false;
        }
        auto slow_ptr = head;
        auto fast_ptr = head->next;
        while (fast_ptr)
        {
            if(slow_ptr == fast_ptr)
            {
                return true;
            }
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            if(fast_ptr)
            {
                fast_ptr = fast_ptr->next;
            }
        }
        return false;
    }
};
#endif //LEETCODECPP_HEADER_NO100TO199_LINKED_LIST_CYCLE_141_H_
