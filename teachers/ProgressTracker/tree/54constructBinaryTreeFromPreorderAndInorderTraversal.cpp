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
TreeNode *build(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int, int> &mp)
{
    if (prestart > preend)
        return NULL;
    TreeNode *root = new TreeNode(preorder[prestart]);
    int inroot = mp[root->val];
    int numleft = inroot - instart;
    root->left = build(preorder, prestart + 1, prestart + numleft, inorder, instart, inroot - 1, mp);
    root->right = build(preorder, prestart + numleft + 1, preend, inorder, inroot + 1, inend, mp);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;
    return build(preorder, 0, n - 1, inorder, 0, n - 1, mp);
}