//
// Created by zlc on 2021/7/9.
//

#include "preordertree.h"


// 根据数组生成二叉树，如果数值为-1则表示空位
TreeNode*  TreeHandler::createTree(vector<int>& nums)
{
    TreeNode* root = NULL;
    if (nums.empty())           // 首先进行判空
    {
        return root;
    }

    root = new TreeNode(nums[0]);

    queue<TreeNode*> q;     // 建立队列         =============》 使用队列
    q.push(root);           // 存入根结点

    for (unsigned int i=1; i<nums.size(); )
    {
        TreeNode* p = q.front();

        // 左子树
        if (nums[i] != -1)  // 不为空
        {
            TreeNode *l = new TreeNode(nums[i]);
            p->left_child = l;
            q.push(l);
            i ++;
        }
        else
            i ++;
        // 右子树
        if (i < nums.size() && nums[i] != -1)   // 不为空
        {
            TreeNode* r = new TreeNode(nums[i]);
            p->right_child = r;
            q.push(r);
            i ++;
        }
        else
            i ++;

        q.pop();
    }

    return root;
}

void TreeHandler::printTree(TreeNode* root)
{
    cout << "pre: ";
    pre_OrderTree(root);        // 递归版先序遍历
    cout << endl;

    cout << "mid: ";
    mid_OrderTree(root);
    cout << endl;
}

// 递归删除节点
void TreeHandler::deleteTree(TreeNode* root)
{
    if (!root)      // 判空
        return;

    deleteTree(root->left_child);
    deleteTree(root->right_child);

    delete root;
}

// 递归版
void TreeHandler::pre_OrderTree(TreeNode* root)
{
    if (!root)      // 判空
        return;

    cout << root->data << " ";
    pre_OrderTree(root->left_child);
    pre_OrderTree(root->right_child);
}

// 非递归先序遍历二叉树git
void TreeHandler::my_PreOrder(TreeNode* root)
{
    cout << "my_pre: ";

    if (!root)
        return;

    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty())
    {
        TreeNode* p = stk.top();
        cout << p->data << " ";

        stk.pop();

        if (p->right_child) // 结合栈的特性，当前节点有右节点的话，先存入右节点
        {
            stk.push(p->right_child);
        }
        if (p->left_child)  // 后存入左子树，也就是先弹出左子树
        {
            stk.push(p->left_child);
        }
    }
    cout << endl;
}

// 中序遍历
void TreeHandler::mid_OrderTree(TreeNode* root)
{
    if (!root)      // 判空
        return;

    mid_OrderTree(root->left_child);
    cout << root->data << " ";
    mid_OrderTree(root->right_child);
}

