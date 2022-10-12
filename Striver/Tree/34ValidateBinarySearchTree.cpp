/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:
https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg
Input: root = [2,1,3]
Output: true

Example 2:
https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.*/

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

// in this approach, we made use of the fact that traveral in inorder is always sorted
// so we take a bool variable which false, we also took a prev value to compare with new value
// we made it out of negative int range so that the when the even the least int number is greater than it.
// then we traverse the the tree and check if next is greater than prev, if it is, condition is maintained and
// we prev as next now, to compare it with the upcoming value
// if it isn't, we make ans false and return
bool ans = true;
long long prev = -215748968, nex;
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    nex = root->val;
    if (nex > prev)
    {
        prev = next;
    }
    else
    {
        ans = false;
        return;
    }
    inorder(root->right);
}
bool isValidBST(TreeNode *root)
{
    inorder(root);
    return ans;
}