//
// Created by Dong Li on 9/6/21.
//

#ifndef LEETCODECPP_HEADER_NO300TO399_TOP_K_FREQUENT_ELEMENTS_347_H_
#define LEETCODECPP_HEADER_NO300TO399_TOP_K_FREQUENT_ELEMENTS_347_H_
class Top_K_Frequent_Elements_347 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_feq_map;
        for(auto i : nums)
        {
            if(num_feq_map.find(i) != num_feq_map.end())
            {
                num_feq_map[i]++;
            }
            else
            {
                num_feq_map[i] = 1;
            }
        }
        vector<pair<int,int>> max_heap(num_feq_map.size());
        int index = 0;
        for(auto it : num_feq_map)
        {
            max_heap[index] = it;
            index++;
        }
        int n = max_heap.size();

        for(int i = (n - 1) / 2; i >= 0; i--)
        {
            int j = i;
            while((j + 1) * 2 - 1 < n)
            {
                int left_node = (j + 1) * 2 - 1;
                int right_node = (j + 1) * 2;
                if(right_node < n)
                {
                    int next_index = max_heap[left_node].second > max_heap[right_node].second ? left_node : right_node;
                    if(max_heap[j].second < max_heap[next_index].second)
                    {
                        swap(max_heap[j], max_heap[next_index]);
                        j = next_index;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(max_heap[j].second < max_heap[left_node].second)
                    {
                        swap(max_heap[j], max_heap[left_node]);
                        j = left_node;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        vector<int> result(k);
        for(int i = 0; i < k; i++)
        {
            result[i] = max_heap[0].first;
            swap(max_heap[0], max_heap[n - 1 - i]);
            int j = 0;
            while((j + 1) * 2 - 1 < n - 1 - i)
            {
                int left_node = (j + 1) * 2 - 1;
                int right_node = (j + 1) * 2;
                if(right_node < n - i - 1)
                {
                    int next_index = max_heap[left_node].second > max_heap[right_node].second ? left_node : right_node;
                    if(max_heap[j].second < max_heap[next_index].second)
                    {
                        swap(max_heap[j], max_heap[next_index]);
                        j = next_index;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(max_heap[j].second < max_heap[left_node].second)
                    {
                        swap(max_heap[j], max_heap[left_node]);
                        j = left_node;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        return result;
    }
};
#endif //LEETCODECPP_HEADER_NO300TO399_TOP_K_FREQUENT_ELEMENTS_347_H_
