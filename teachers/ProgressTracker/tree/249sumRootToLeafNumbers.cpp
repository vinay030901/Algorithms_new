#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int fun(TreeNode *root, int cur)
{
    if (!root)
        return 0;
    cur = cur * 10 + root->val;
    if (!root->left && !root->right)
        return cur;
    return fun(root->left, cur) + fun(root->right, cur);
}
int sumNumbers(TreeNode *root)
{
    return fun(root, 0);
}
int main() {
    return 0;
}