//
// Created by zlc on 2021/7/9.
//

#include "preordertree.h"


int main(int argc, char* *argv)
{
    // std::vector<int> v({1, 2, -1, 4, 5, 6});
    std::vector<int> v({1, 2, 3, 4, 5, 6, 7, 8, -1, 9, -1, -1, 10, -1, 11});

    TreeHandler* th = new TreeHandler();
    TreeNode* root  = th->createTree(v);        // 创建二叉树

    th->printTree(root);        // 打印先序和中序遍历的结果
    th->my_PreOrder(root);
    // th->pre_OrderTree(root);

    th->deleteTree(root);
    delete th;

    return 0;
}
