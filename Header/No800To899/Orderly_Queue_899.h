//
// Created by Dong Li on 9/5/21.
//

#ifndef LEETCODECPP_HEADER_NO900TO999_ORDERLY_QUEUE_899_H_
#define LEETCODECPP_HEADER_NO900TO999_ORDERLY_QUEUE_899_H_
class Orderly_Queue_899 {
public:
    string orderlyQueue(string s, int k) {
        // 只要k大于等于2一定可以
        if(k <= 1)
        {
            int smallest = 0;
            for(int i = 0; i < s.length(); i++)
            {
                if(s[i] < s[smallest])
                {
                    smallest = i;
                }
            }

            vector<int> table;
            for(int i = 0; i < s.length(); i++)
            {
                if(s[i] == s[smallest])
                {
                    table.push_back(i);
                }
            }

            int loop_times = 0;
            while (table.size() > 1 && ++loop_times < s.length())
            {
                vector<int> tmp_table;
                auto next_smallest = (table[0] + loop_times) % s.length();
                for(int i = 1; i < table.size(); i++)
                {
                    auto next_index = (table[i] + loop_times) % s.length();
                    if(s[next_index] < s[next_smallest])
                    {
                        next_smallest = next_index;
                    }
                }
                for(int i = 0; i < table.size(); i++)
                {
                    auto next_index = (table[i] + loop_times) % s.length();
                    if(s[next_index] == s[next_smallest])
                    {
                        tmp_table.push_back(table[i]);
                    }
                }
                table = tmp_table;
            }
            smallest = table[0];

            return s.substr(smallest, s.length() - smallest) + s.substr(0, smallest);
        }
        else
        {
            // 当k大于等于2的时候，我们实际上一定能做到最优解，一定能得到字典序排序的结果
            /**
             * (1) 假设s是这样的，...表示略过的无数字符，1表示最小的字符。 ...1...
             * (2) 那么很显然我们通过把1前面的所有字符移动到尾部就可以让1到头部。
             * (3) 1...2... 然后字符串变成了这样，2表示第二小的
             * (4) 由于k大于等于2，意味着我们可以继续移动紧挨着1的k个字符串变成
             *     1,2...
             * (5) 继续找第三小的字符，一直重复上述步骤，就可以得到一个排好序的字符串
             */
            vector<int> letter_table(27, 0);
            for(char c : s)
            {
                letter_table[c - 'a']++;
            }
            string result(s.size(), '1');
            int index = 0;
            for(int i = 0; i < letter_table.size(); i++)
            {
                for(int j = 0; j < letter_table[i]; j++)
                {
                    result[index] = 'a' + i;
                    index++;
                }
            }
            return result;
        }
    }
};
#endif //LEETCODECPP_HEADER_NO900TO999_ORDERLY_QUEUE_899_H_
