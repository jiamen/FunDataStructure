//
// Created by zlc on 2021/7/9.
//

#ifndef _FUNDATASTRUCTURE_PREODERTREE_H_
#define _FUNDATASTRUCTURE_PREODERTREE_H_

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left_child;
    TreeNode* right_child;

    TreeNode() { TreeNode(0); }

    TreeNode(int _data) : data(_data)
    {
        left_child  = NULL;
        right_child = NULL;
    }
};


class TreeHandler
{
public:
    TreeNode* createTree(vector<int>& nums);

    void deleteTree(TreeNode* root);
    void printTree(TreeNode* root);

    // 递归版
    void pre_OrderTree(TreeNode* root);
    void mid_OrderTree(TreeNode* root);
    void post_OrderTree(TreeNode* root);

    // 非递归版
    void my_PreOrder(TreeNode* root);
    void my_MidOrder(TreeNode* root);
    void my_PostOrder(TreeNode* root);
};



#endif // _FUNDATASTRUCTURE_PREODERTREE_H_
