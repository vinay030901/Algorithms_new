/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2*/

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

// surprisingly, this approach was faster than 93% of the submissions

// we will use a traverasl technique for doing it in O(N) time and constant space
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // what we do here is move in the tree and if we find other p and q, we will return the node
    // so when any node will get both p and q from different sides, it will return its own value and we will get the LCA

    if (root == NULL || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root; // if both are not null, we will return root
}

// our second approach take account of the bst
// here we will traverse the bst, if the values of p and q are less than root, then we move to left and else we move right
// but if we get a condition where p is greater than root and q is less than root, or p is less while q is great
// then we can see that both of these will be in different sides and therefore, this is our answer
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (true)
    {
        if (root == p || root == q)
            return root;
        else if (root->val > p->val and root->val > q->val)
            root = root->left;
        else if (root->val < p->val and root->val < q->val)
            root = root->right;
        else if (root->val < p->val and root->val > q->val)
            return root;
        else if (root->val > p->val and root->val < q->val)
            return root;
    }
    return root;
}