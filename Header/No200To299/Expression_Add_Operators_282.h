#ifndef LEETCODECPP_EXPRESSION_ADD_OPERATORS_282_H
#define LEETCODECPP_EXPRESSION_ADD_OPERATORS_282_H

#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Expression_Add_Operators_282 {
private:
    // cur: {string} expression generated so far.
    // pos: {int}    current visiting position of num.
    // cv:  {long}   cumulative value so far.
    // pv:  {long}   previous operand value.
    // op:  {char}   previous operator used.
    void dfs(std::vector<string>& res, const string& num, const int target, string cur, int pos, const long cv, const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
        } else {
            for (int i=pos+1; i<=num.size(); i++) {
                string t = num.substr(pos, i-pos);
                long now = stol(t);
                if (to_string(now).size() != t.size()) continue;
                dfs(res, num, target, cur+'+'+t, i, cv+now, now, '+');
                dfs(res, num, target, cur+'-'+t, i, cv-now, now, '-');
                dfs(res, num, target, cur+'*'+t, i, (op == '-') ? cv+pv - pv*now : ((op == '+') ? cv-pv + pv*now : pv*now), pv*now, op);
            }
        }
    }

public:
    /**
     * @param dfs解法，实际上也是回溯，但是这个方法不超时
     * 时间复杂度是一样的
     */
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        for (int i=1; i<=num.size(); i++) {
            string s = num.substr(0, i);
            long cur = stol(s);
            // "012" -> 12 这种情况是被忽视的
            if (to_string(cur).size() != s.size()) continue;
            dfs(res, num, target, s, i, cur, cur, '#');         // no operator defined.
        }

        return res;
    }


    /**
     * @param 暴力回溯
     */
    vector<string> addOperators2(string num, int target) {
        // (1) 先进行分割
        // (2) 随后对每个分割进行穷举符号计算
        // 总复杂度 是 4^n
        if(num.size() == 0)
        {
            return {};
        }
        vector<string> result;

        int n = 1 << (num.size() - 1);
        int i = 0;
        while(i++ < n)
        {
            //(1)
            vector<long int> numbers;
            string curr_num = "";
            int str_begin_index = 0;
            int str_length = 1;
            int bit_j = i - 1;
            while(bit_j > 0)
            {
                if(bit_j % 2 == 1)
                {
                    numbers.push_back(stol(num.substr(str_begin_index, str_length)));
                    str_begin_index += str_length;
                    str_length = 0;
                }
                bit_j /= 2;
                str_length++;
            }
            if(num[str_begin_index] == '0' && str_begin_index < num.size() - 1)
            {
                continue;
            }
            numbers.push_back(stol(num.substr(str_begin_index)));

            //(2)
            if(numbers.size() <= 1)
            {
                if(numbers[0] == target)
                {
                    result.push_back(to_string(numbers[0]));
                }
                continue;
            }
            vector<char> op_vec(numbers.size() - 1, '*');
            int total_op_size = pow(3, op_vec.size());
            // 0 -> '*', 1 -> '+', 2 -> '-'
            int curr_op_partten = 0;
            while(curr_op_partten < total_op_size)
            {
                int bit_op_j = curr_op_partten;
                int iterate_times = 0;
                string result_str = "";
                while(bit_op_j > 0)
                {
                    switch (bit_op_j % 3)
                    {
                        case 0:
                            op_vec[iterate_times] = '*';
                            break;
                        case 1:
                            op_vec[iterate_times] = '+';
                            break;
                        case 2:
                            op_vec[iterate_times] = '-';
                            break;
                        default:
                            cerr << "error!";
                            exit(1);
                            break;
                    }
                    bit_op_j /= 3;
                    iterate_times++;
                }

                // cout << numbers[0];
                // for(int num_of_num = 1; num_of_num < numbers.size(); num_of_num++)
                // {
                //     cout << op_vec[num_of_num - 1] << numbers[num_of_num]; 
                // }
                // cout << endl;

                // (3)最后是四则运算计算结果
                stack<long int> num_stack;
                stack<char> op_stack;                
                for(int it = 0; it < op_vec.size(); it++)
                {   
                    result_str += to_string(numbers[it]);
                    result_str += op_vec[it];
                    num_stack.push(numbers[it]);
                    switch(op_vec[it])
                    {
                        case '-':
                        case '+':
                            if(!op_stack.empty())
                            {
                                int num1 = num_stack.top();
                                num_stack.pop();
                                int num2 = num_stack.top();
                                num_stack.pop();
                                if(op_stack.top() == '+')
                                {
                                    num_stack.push(num2 + num1);
                                }
                                else if(op_stack.top() == '-')
                                {
                                    num_stack.push(num2 - num1);
                                }
                                else
                                {
                                    num_stack.push(num2 * num1);
                                }
                                op_stack.pop();
                            }
                            op_stack.push(op_vec[it]);
                            break;
                        case '*':
                            if(!op_stack.empty() && op_stack.top() == '*')
                            {
                                int num1 = num_stack.top();
                                num_stack.pop();
                                int num2 = num_stack.top();
                                num_stack.pop();
                                num_stack.push(num1 * num2);
                                op_stack.pop();
                            }
                            op_stack.push(op_vec[it]);
                            break;
                        default:
                            cerr << "error!";
                            exit(1);
                            break;
                    }
                }
                result_str += to_string(numbers[numbers.size() - 1]);
                num_stack.push(numbers[numbers.size() - 1]);
                while (!op_stack.empty())
                {
                    long int num1 = num_stack.top();
                    num_stack.pop();
                    long int num2 = num_stack.top();
                    num_stack.pop();
                    if(op_stack.top() == '+')
                    {
                        num_stack.push(num1 + num2);
                    }
                    else if(op_stack.top() == '-')
                    {
                        num_stack.push(num2 - num1);
                    }
                    else 
                    {
                        num_stack.push(num1 * num2);
                    }
                    op_stack.pop();
                }
                if(num_stack.top() == target)
                {
                    result.push_back(result_str);
                }

                curr_op_partten++;
            }


            // for(auto s : numbers)
            // {
            //     cout << s << ", ";
            // }
            // cout << endl;
        }

        return result;
    }
};

#endif