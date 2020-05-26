#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "SolutionList1.h"
using namespace std;
struct MyStruct{
    string a;
    string b;
};

int main() {
    vector<int> vec{0,1,0,0,0,0,0,1,0,1,1,0,0};
    ContiguousArray contiguousArray;
    cout << contiguousArray.findMaxLength(vec);
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
