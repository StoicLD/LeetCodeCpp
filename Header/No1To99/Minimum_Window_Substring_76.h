//
// Created by lidong on 2021/7/21.
//

#ifndef LEETCODECPP_MINIMUM_WINDOW_SUBSTRING_76_H
#define LEETCODECPP_MINIMUM_WINDOW_SUBSTRING_76_H

#include <map>
#include <list>

using namespace std;

class Minimum_Window_Substring_76
{
public:
    struct ListNode
    {
        char val;
        int index_in_s;
    };

    struct MapNode
    {
        char val = 0;
        int total_in_t = 0;
        int curr_num_in_s = 0;
    };


    string minWindow(string s, string t)
    {
        // 需要一个list和一个map，map用于记录当前窗口内的字符信息
        // list用于顺序记录当前窗口下，t中的字符在s中的下标
        int start_window = 0, end_window = 0;
        int result_start = 0, result_end = 0;
        int result_length = INT32_MAX;
        int valid_length_of_s_list = 0;
        unordered_map<char, MapNode> t_map;
        list<ListNode> s_list;
        for (auto val : t)
        {
            if (t_map.find(val) != t_map.end())
            {
                t_map[val].total_in_t++;
            }
            else
            {
                t_map[val] = MapNode{val, 1, 0};
            }
        }

        for (; end_window < s.size(); end_window++)
        {
            char end_val = s[end_window];
            if(t_map.find(end_val) != t_map.end())
            {
                t_map[end_val].curr_num_in_s++;
                s_list.push_back(ListNode{end_val, end_window});
                if(t_map[end_val].curr_num_in_s <= t_map[end_val].total_in_t)
                {
                    valid_length_of_s_list++;
                }

                start_window = s_list.front().index_in_s;
                char start_val = s[start_window];
                while(t_map[start_val].curr_num_in_s > t_map[start_val].total_in_t)
                {
                    t_map[start_val].curr_num_in_s--;
                    s_list.pop_front();
                    start_window = s_list.front().index_in_s;
                    start_val = s[start_window];
                }
                if(valid_length_of_s_list == t.size())
                {
                    if(end_window - start_window < result_length)
                    {
                        result_start = start_window;
                        result_end = end_window;
                        result_length = end_window - start_window;
                    }
                }
            }
            
        }
        return result_length == INT32_MAX ? "" : s.substr(result_start, result_length + 1);
    }
};

#endif //LEETCODECPP_MINIMUM_WINDOW_SUBSTRING_76_H
