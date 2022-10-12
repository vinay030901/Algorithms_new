/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool check(TreeNode *l, TreeNode *r)
{
    /*if (l == NULL && r == NULL)
        return true;
    else if (!l and r)
        return false;
    else if (l and !r)
        return false;*/
    if(!l || !r) return l==r;
    return l->val == r->val && check(l->right, r->left) && check(l->left, r->right);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return check(root->left, root->right);
}