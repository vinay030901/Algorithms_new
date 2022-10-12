/*
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:
https://assets.leetcode.com/uploads/2020/01/30/sample_1_1709.png
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.


Example 2:
https://assets.leetcode.com/uploads/2020/01/30/sample_2_1709.png
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.*/

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
class NodeValue
{
public:
    int maxNode, minNode, sum;
    bool isBst;
    NodeValue(int minNode, int maxNode, bool isBst, int sum)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
        this->isBst = isBst;
    }
    NodeValue() {}
};
class Solution
{
public:
    int mx = INT_MIN;
    NodeValue findMax(TreeNode *root)
    {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, true, 0);
        auto left = findMax(root->left);
        auto right = findMax(root->right);

        NodeValue nv;
        nv.isBst = (left.isBst and right.isBst and left.maxNode < root->val and
                    root->val < right.minNode);
        nv.minNode = min(root->val, left.minNode);
        nv.maxNode = max(root->val, right.maxNode);
        if (nv.isBst)
        {
            nv.sum = left.sum + right.sum + root->val;
            mx = max(nv.sum, mx);
        }
        return nv;
    }
    int maxSumBST(TreeNode *root)
    {
        auto x = findMax(root);
        if (mx > 0)
            return mx;
        return 0;
    }
};