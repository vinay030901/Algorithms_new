#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};
bool check(TreeNode *l, TreeNode *r)
{
    if (!l || !r)
        return l == r;
    return (l->val == r->val) && check(l->left, r->right) && check(l->right, r->left);
}
bool isSymmetric(TreeNode *root)
{
    return check(root->left, root->right);
}