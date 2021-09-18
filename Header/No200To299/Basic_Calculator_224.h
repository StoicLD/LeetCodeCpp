#ifndef LEETCODECPP_BASIC_CALCULATOR_224_H
#define LEETCODECPP_BASIC_CALCULATOR_224_H
#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Basic_Calculator_224
{
public:
    int calculate(string s) 
    {
        // (1)记录开闭括号的个数
        // (2)往下遍历符号，查看stack top的符号
        stack<int> num_stack;
        stack<char> op_stack;
        int i = 0;
        string num_str = "";
        string pre_str = "";
        while(i < s.length())
        {
            switch (s[i])
            {
            case ' ':
                break;
            case ')':
                /* code */
                while (op_stack.top() != '(')
                {
                    calculate_helper(num_stack, op_stack);
                }
                op_stack.pop();
                pre_str = ")";
                break;
            case '(':
                /* code */
                op_stack.push(s[i]);
                pre_str = "(";
                break;
            case '*':
            case '/':
                /* code */
                if(!op_stack.empty())
                {
                    if(op_stack.top() == '*' || op_stack.top() == '/')
                    {
                        // 此时直接计算前一个优先级符号结合
                        // 2 - 3 * 4 * 5

                        // 这里不应该出现empty，否则是非法输入
                        calculate_helper(num_stack, op_stack);
                    }
                }
                op_stack.push(s[i]);
                pre_str = s[i];
                break;
            case '+':
                /* code */
                if(!op_stack.empty())
                {
                    if(op_stack.top() != '(')
                    {
                        calculate_helper(num_stack, op_stack);
                    }
                }
                op_stack.push(s[i]);
                pre_str = s[i];
                break;
            case '-':
                /* code */
                if(pre_str == "" || pre_str == "(")
                {
                    // num_str = "-" + num_str;
                    num_stack.push(0);
                }
                else
                {
                    if(!op_stack.empty() && op_stack.top() != '(')
                    {
                        calculate_helper(num_stack, op_stack);
                    }
                    // op_stack.push(s[i]);
                }
                op_stack.push(s[i]);
                pre_str = s[i];
                break;                                
            
            default:
                // 其余情况下是数字
                while(i < s.length() && s[i] <= '9' && s[i] >= '0')
                {
                    num_str += s[i];
                    i++;
                }
                num_stack.push(stoi(num_str));
                pre_str = num_str;
                num_str = "";
                continue;
            }
            i++;
        }

        if(num_str != "")
        {
            num_stack.push(std::stoi(num_str));
        }
        while (!op_stack.empty())
        {
            calculate_helper(num_stack, op_stack);
        }   

        return num_stack.top();
    }

    void calculate_helper(stack<int>& num_stack, stack<char>& op_stack) 
    {
        if(num_stack.size() >= 2 && op_stack.size() >= 1 && op_stack.top() != '(' && op_stack.top() != ')')
        {
            auto num1 = num_stack.top();
            num_stack.pop();
            auto num2 = num_stack.top();
            num_stack.pop();
            switch (op_stack.top())
            {
            case '+':
                /* code */
                num_stack.push(num2 + num1);
                break;
            case '-':
                /* code */
                num_stack.push(num2 - num1);
                break;
            case '*':
                /* code */
                num_stack.push(num2 * num1);
                break;
            case '/':
                /* code */
                num_stack.push(num2 / num1);
                break;                
            default:
                cout << "invalid op_stack top element" << endl;
                break;
            }
            op_stack.pop();
        }
        else
        {
            cout << "should not be less than 2" << endl;
        }
    }
};

#endif