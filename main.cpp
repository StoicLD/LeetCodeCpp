#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "No200To299/Basic_Calculator_224.h"
#include "No200To299/Expression_Add_Operators_282.h"
using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */

struct TestNode {
    int val;
};

int main()
{
    Expression_Add_Operators_282 test;
    auto result = test.addOperators("123456789", 45);
    for(auto s : result)
    {
        cout << s << endl;
    }
    // string s1 = "1 + 3";                // 4
    // string s2 = "-1 + (3 -1 )";         // 1
    // string s3 = "3 + 5* 4 -2+8/2";      // 25
    // string s4 = "5-6*(3*4 + 7)";        // -109
    // string s5 = "3 + (-4 + 3 * (5 + 7 - (2*3)) - 4)";               // 13
    // string s6 = "-3 + 4 - (1 + 3 - (4 - 2) - (10 - 3))";            // 6
    // string s7 = " 2-1 + 2 ";
    // string s8 = "-(-(-1))";
    // string s9 = "-((-1))";
    // string s10 = "1-((-1))";
    // string s11 = "1*2-3/4+5*6-7*8+9/10";        // -24
    // string s12 = "1*2-3/4+5*6";        // 32
    // Basic_Calculator_224 test; 
    // cout << (test.calculate(s1) == 4) << endl;
    // cout << (test.calculate(s2) == 1) << endl;
    // cout << (test.calculate(s3) == 25) << endl;
    // cout << (test.calculate(s4) == -109) << endl;
    // cout << (test.calculate(s5) == 13) << endl;
    // cout << (test.calculate(s6) == 6) << endl;
    // cout << (test.calculate(s7) == 3) << endl;

    // cout << (test.calculate(s8) == -1) << endl;
    // cout << (test.calculate(s9) == 1) << endl;
    // cout << (test.calculate(s10) == 2) << endl;
    // cout << (test.calculate(s11) == -24) << endl;
    // cout << (test.calculate(s12) == 32) << endl;
    // assert(test.calculate(s3) == 4);
}
