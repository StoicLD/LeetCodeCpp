#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Header/CourseSchedule.h"
using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */
int main() {
    CourseSchedule_207 cs;
    vector<vector<int> > s{vector<int>{1,0}};
    cout << cs.canFinish(2, s) << endl;

    vector<vector<int> > s2{vector<int>{1,0}};

    return 0;
}
