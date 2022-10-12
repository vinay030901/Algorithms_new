/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values.
If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// this method uses inorder to build the tree, first we will find the inorder of the bst, we will do this using the findTree function
vector<TreeNode *> tree;
void findTree(TreeNode *root, vector<TreeNode *> &tree)
{
    if (root == NULL)
        return;

    findTree(root->left, tree);
    tree.push_back(root);
    findTree(root->right, tree);
}
// now when we get the inorder traversal, we will make the binary tree using a simple binary search type approach
TreeNode *buildTree(int i, int j)
{
    if (i > j)
        return NULL;
    int mid = (i + j) / 2;
    TreeNode *root = tree[mid];
    root->left = buildTree(i, mid - 1);
    root->right = buildTree(mid + 1, j);
    return root;
}
TreeNode *balanceBST(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    findTree(root, tree);
    int n = tree.size();
    root = buildTree(0, n - 1);
    return root;
}

