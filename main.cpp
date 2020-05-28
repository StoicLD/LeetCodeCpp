#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */
int main() {

    cout << "++i" << endl;
    for(int i = 0; i < 10; )
    {
        cout << ++i << endl;
    }

    cout << "i++" << endl;
    for(int i = 0; i < 10; )
    {
        cout << i++ << endl;
    }

    return 0;
}
