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
void invert(TreeNode *root)
{
    if (!root)
        return;
    invert(root->left);
    invert(root->right);
    swap(root->left, root->right);
}
TreeNode *invertTree(TreeNode *root)
{
    invert(root);
    return root;
}