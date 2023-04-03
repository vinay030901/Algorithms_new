/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree),
construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val,
and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:
https://assets.leetcode.com/uploads/2019/03/06/1266.png
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]*/

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

// the first method is simple, we will traverse the vector value and insert all of them one by one
// it has the time complexity of n*h because for n nodes and height h, but if tree is skewed, it can become n*n
// this is absolute brute method
TreeNode *insert(TreeNode *root, int key)
{
    TreeNode *dummy = root;
    while (root)
    {
        if (root->val > key)
        {
            if (!root->left)
            {
                root->left = new TreeNode(key);
                return dummy;
            }
            root = root->left;
        }
        else
        {
            if (!root->right)
            {
                root->right = new TreeNode(key);
                return dummy;
            }
            root = root->right;
        }
    }
    return dummy;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int n = preorder.size();
    if (n == 1)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        return root;
    }
    TreeNode *root = new TreeNode(preorder[0]);

    for (int i = 1; i < preorder.size(); i++)
    {
        root = insert(root, preorder[i]);
    }
    return root;
}

// another method: we have preorder, so we can sort the preorder and make it inorder, then we make a binary tree using preorder and 
// inorder, time complexity is O(NLogN)

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
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    // at first, we make a map for inorder for the index, to check the position of left subtree and right 
    vector<int>inorder=preorder;
    sort(inorder.begin(),inorder.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}

// the third solution is best and linear
// we make proper use of bst here as we traverse the tree
// what we do is have a upper bound value with us, start with int_max, later it will change
// so in helper function, we check if the upper bound is greater than vector value, if it is, we will enter the function
// or else we will return NULL
// now we make a new root using that vector value
// and try to add it to the left side, if the root value is greater again, the new value will be added or else, it will return NULL
// if it return NULL, we will now compare with the bound value, that is the above the root, and compare
// this process will flow like that only
TreeNode *helper(vector<int> &preorder, int &i, int bound)
{
    if (i == preorder.size() || preorder[i] > bound)
        return NULL;
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = helper(preorder, i, root->val);
    root->right = helper(preorder, i, bound);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return helper(preorder, i, INT_MAX);
}