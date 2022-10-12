/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.



Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.*/

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

// the solution of this question is like diameter of binary tree, where we found the max height of the node
// here we are finding the max value 

// we went to every node and find the max sum of the node, we will have a separate variable for this.
// we will return the max of lh and rh value so that we can check for the best path
// let's understand it using code 
int mx = INT_MIN;
int maxSum(TreeNode *root)
{
    if (root == NULL) // if root is null, we will return 0
        return 0;
    int leftSum = maxSum(root->left); // here we will find the left height of tree, the thing is, this is the max value of left 

    if (leftSum < 0) leftSum = 0; // if we get negative value from left, then we neglect it, the point is instead of adding 
    // negative to our value, we will not take that node or side

    int rightSum = maxSum(root->right); // same is the case for right side too

    if (rightSum < 0) rightSum = 0;

    mx = max(mx, (leftSum + rightSum + root->val));// here we are calculating the max of adding the leftsum, rightsum and current node

    return root->val + max(leftSum, rightSum);// returning the best path for the node above in the tree
}
int maxPathSum(TreeNode *root)
{
    int x = maxSum(root);
    return mx;
}