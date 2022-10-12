/*
Given a BST, find the inorder predecessor of a given key in it. If the key does not lie in the BST,
return the previous greater node (if any) present in the BST.

An inorder predecessor of a node in the BST is the previous node in the inorder traversal of it.

For example, consider the following tree:
https://www.techiedelight.com/wp-content/uploads/Inorder-successor-and-Inorder-predecessor.png
Inorder successor and Inorder predecessor


The inorder predecessor of 8 does not exist.
The inorder predecessor of 10 is 8
The inorder predecessor of 12 is 10
The inorder predecessor of 20 is 16*/
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

TreeNode *inorderPredecessor(TreeNode *root, TreeNode *key)
{
    TreeNode *predecessor = NULL;
    while (root != NULL)
    {
        if (root->val >= key->val)
        {
            root = root->left;
        }
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *key)
{
    TreeNode *successor = NULL;
    while (root != NULL)
    {
        if (root->val <= key->val)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}