#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int mx = INT_MIN;
int findMax(TreeNode *root)
{
    if (!root)
        return 0;
    int left = findMax(root->left);
    if (left < 0)
        left = 0;
    int right = findMax(root->right);
    if (right < 0)
        right = 0;
    mx = max(mx, left + right + root->val);
    return root->val + max(left, right);
}
int maxPathSum(TreeNode *root)
{
    findMax(root);
    return mx;
}