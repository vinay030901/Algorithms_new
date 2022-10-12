/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder
is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
https://assets.leetcode.com/uploads/2021/02/19/tree.jpg
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]*/

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

/*example we have
inorder: [40,20,50,10,60,30]-> left root right
preorder: [10,20,40,50,30,60]-> root left right

so we know that 10 is the root of our binary tree, so all the nodes on the left that is(40,20,50) will be the part of left subtree
and (60,30) would be in right subtree
so we can attach them using recursion, and the new parts will same task

now left subtree:
inorder: [40,20,50]
preorder: [20,40,50]
now 20 is the root here, and 40 is left and 50 is right

now right subtree
inorder: [60,30]
preorder: [30,60]
now 30 is the root here, so 60 is left

so we did made the whole tree

so implementation might be tricky here*/

TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);

    int inRoot = mp[root->val];
    int numLeft = inRoot - inStart;

    root->left = build(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, mp);
    root->right = build(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // at first, we make a map for inorder for the index, to check the position of left subtree and right subtree
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}

