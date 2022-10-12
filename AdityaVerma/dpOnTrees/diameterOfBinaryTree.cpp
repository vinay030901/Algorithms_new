/*
so, here we need to find the diameter of two given nodes in a tree
*/
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
int solve(TreeNode *root, int &res)
{
    if (root == NULL)
        return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = 1 + max(l, r);
    int ans = max(temp, l + r);
    res = max(res, ans);
    return temp;
}
int main()
{
    int ans = INT_MIN;
    TreeNode *root = new TreeNode();
    solve(root, ans);
    return 0;
}