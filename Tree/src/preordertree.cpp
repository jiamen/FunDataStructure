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

    cout << "post: ";
    post_OrderTree(root);
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
// 非递归先序遍历二叉树
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

// 递归版中序遍历
void TreeHandler::mid_OrderTree(TreeNode* root)
{
    if (!root)      // 判空
        return;

    mid_OrderTree(root->left_child);
    cout << root->data << " ";
    mid_OrderTree(root->right_child);
}
// 非递归中序遍历二叉树
void TreeHandler::my_MidOrder(TreeNode* root)
{
    cout << "my_mid: ";
    if (!root)
        return;

    stack<TreeNode*> stk;

    TreeNode* p = root;
    while (p || !stk.empty())
    {
        while(p)
        {
            stk.push(p);
            p = p->left_child;
        }
        if (!stk.empty())
        {
            p = stk.top();  // 记录当前栈顶
            stk.pop();      // 从栈中弹出栈顶
            cout << p->data << " ";
            p = p->right_child;
        }
    }
    cout << endl;
}
// 步骤总结：
// ① 只要节点不空就存节点并指向左子树
// ② 记录、弹出、打印栈顶，再将当前节点右子树进行记录
// ③ 依旧存入当前节点，并指向当前节点的左子树


// 递归版后序遍历
void TreeHandler::post_OrderTree(TreeNode* root)
{
    if (!root)      // 判空
        return;

    post_OrderTree(root->left_child);
    post_OrderTree(root->right_child);
    cout << root->data << " ";
}
// 非递归后序遍历二叉树：比较麻烦，另一种解法是采用一个指针保存上次遍历的节点，避免重复遍历），使用两个栈，一个负责按照“根、右、左”的顺序入栈出栈，另一个负责逆序记录输出的数据。
void TreeHandler::my_PostOrder(TreeNode *root)
{
    cout << "my_post: ";
    if (!root)
        return;

    stack<TreeNode*> stk1;  // 辅助栈
    stack<TreeNode*> stk2; // 逆序记录遍历的数据
    TreeNode* p = root;
    while(p || !stk1.empty())
    {
        if (p)
        {
            stk2.push(p);
            stk1.push(p);
            p = p->right_child;
        }
        else
        {
            p = stk1.top();
            stk1.pop();
            p = p->left_child;
        }
    }

    while (!stk2.empty())
    {
        p = stk2.top();
        stk2.pop();
        cout << p->data << " ";
    }
    cout << endl;
}
