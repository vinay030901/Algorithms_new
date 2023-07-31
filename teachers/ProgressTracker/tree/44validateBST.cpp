#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool fun(TreeNode *root, TreeNode *&prev)
{
    if (!root)
        return true;
    if (!fun(root->left, prev))
        return false;
    if (prev && prev->val >= root->val)
        return false;
    prev = root;
    return fun(root->right, prev);
}
bool isValidBST(TreeNode *root)
{
    TreeNode *prev = NULL;
    return fun(root, prev);
}