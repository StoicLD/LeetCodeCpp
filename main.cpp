#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "PossibleBipartition.h"
using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */
int main() {
    PossibleBipartition_886 pb;
    vector<vector<int> > vec{{1,2},{3,4},{4,5},{3,5}};
    vector<vector<int> > vec1{{1,2},{3,4},{4,5},{3,5}};
    vector<vector<int> > vec2{{1,2},{3,4},{4,5},{3,5}};

    cout << pb.possibleBipartition(5, vec) << endl;
    //MyStruct myStruct{"a","b"};
//    cin >> name;
//    if(cin.fail())
//    {
//        cerr << "error !" << endl;
//    }
//    cout << "Please input your age" << endl;
//
//    cin >> age;
//    if(cin.fail())
//    {
//        cerr << "error !" << endl;
//    }
    return 0;
}
