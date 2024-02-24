/*Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.



Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]


Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *build(vector<int> &postOrder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{
    if (postStart > postEnd)
        return NULL;
    TreeNode *root = new TreeNode(postOrder[postEnd]);
    int inRoot = mp[root->val];
    int numLeft = inRoot - inStart;
    root->left = build(postOrder, postStart, postStart + numLeft - 1, inorder, inStart, inRoot - 1, mp);
    root->right = build(postOrder, postStart + numLeft, postEnd - 1, inorder, inRoot + 1, inEnd, mp);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> mp;
    int n = inorder.size();
    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;
    return build(postorder, 0, n - 1, inorder, 0, n - 1, mp);
}
int main()
{
    // Your code here
    return 0;
}