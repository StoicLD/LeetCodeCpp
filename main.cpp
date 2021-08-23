#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "No1To99/Unique_Binary_Search_Trees_96.h"
#include "No600To699/Two_Sum4_Input_is_a_BST_653.h"
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
    Two_Sum4_Input_is_a_BST_653 bst;
    TreeNode root(5);
    root.left = new TreeNode(3);
    root.left->left = new TreeNode(2);
    root.left->right = new TreeNode(4);
    root.right = new TreeNode(6);
    root.right->right = new TreeNode(7);
    cout << bst.findTarget(&root, 9);
}
