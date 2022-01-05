#ifndef LEETCODECPP_MERGE_K_SORTED_LISTS_H
#define LEETCODECPP_MERGE_K_SORTED_LISTS_H


#include<list>
#include <functional>
#include <queue>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class MergeKSortedLists {
public:
    // Method1 O(k * n)
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k <= 0)
        {
            return nullptr;
        }
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        int min_val = 10001;    
    
        list<ListNode*> vec;
        auto smallest_it = vec.begin();
        
        for(int i = 0; i < k; i++)
        {
            if(lists[i])
            {
                vec.push_back(lists[i]);
                if(lists[i]->val < min_val)
                {
                    head = lists[i];
                    min_val = head->val;
                    auto temp_it = vec.end();
                    temp_it--;
                    smallest_it = temp_it;
                }
            }
        }
        
        if(smallest_it != vec.end() && *smallest_it != nullptr)
        {
            *smallest_it = (*smallest_it)->next;
            if(*smallest_it == nullptr)
            {
                vec.erase(smallest_it);
            }
        }
        
        curr = head;
        ListNode* next = nullptr;
        
        while(!vec.empty())
        {
            min_val = 10001;
            for(auto it = vec.begin(); it != vec.end(); it++)
            {
                if(*it && (*it)->val < min_val)
                {
                    next = (*it);
                    min_val = next->val;
                    smallest_it = it;
                }
            }
            curr->next = next;
            curr = next;
            *smallest_it = (*smallest_it)->next;
            if(*smallest_it == nullptr)
            {
                vec.erase(smallest_it);
            }
        }

        return min_val == 10001 ? nullptr : head;
    }
    
    // Method2
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k <= 0)
        {
            return nullptr;
        }
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        int min_val = 10001;    
        int smallest_index = 0;
        int empty_nodes = 0;
    
        vector<ListNode*> vec(k, nullptr);
        for(int i = 0; i < k; i++)
        {
            vec[i] = lists[i];
            if(vec[i] && vec[i]->val < min_val)
            {
                head = vec[i];
                min_val = head->val;
                smallest_index = i;
            }
        }
        if(vec[smallest_index])
        {
            vec[smallest_index] = vec[smallest_index]->next;
        }
        else
        {
            empty_nodes++;    
        }
        curr = head;
        ListNode* next = nullptr;
        
        while(empty_nodes < k)
        {
            min_val = 10001;
            for(int i = 0; i < k; i++)
            {
                if(vec[i] && vec[i]->val < min_val)
                {
                    next = vec[i];
                    min_val = next->val;
                    smallest_index = i;
                }
            }
            if(vec[smallest_index])
            {
                curr->next = next;
                curr = next;
                vec[smallest_index] = vec[smallest_index]->next;                
            }
            else
            {
                empty_nodes++;    
            }
        }

        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* node1, ListNode* node2) {
            return (node1->val) > (node2->val); 
        };
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> p_queue(cmp);
        
        for(auto node : lists)
        {
            auto curr = node;
            while(curr)
            {
                p_queue.push(curr);
                curr = curr->next;
            }
        }
        
        ListNode* head = p_queue.empty() ? nullptr : p_queue.top();
        ListNode* curr = head;
        if(!p_queue.empty())
        {
            p_queue.pop();
        }
        
        while(!p_queue.empty() && p_queue.top())
        {
            curr->next = p_queue.top();
            curr = curr->next;
            p_queue.pop();
        }
        return head;
    }
};

#endif