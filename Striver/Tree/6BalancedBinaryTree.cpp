/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true*/
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

// USING HEIGHT METHOD AT EVERY NODE- O(N^2)
int findHeight(TreeNode *root)
{
    // recursive solution
    if (root == NULL)
        return 0;
    int l = findHeight(root->left);
    int r = findHeight(root->right);
    return 1 + max(l, r);
}
bool isBalanced(TreeNode *root)
{
    // the first method is basic, that is find the height of every left and right node and check if height difference is 
    // not more than 1 here
    if (root == NULL)
        return true;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if (abs(lh - rh) > 1)
        return false;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    if (!left || !right)
        return false;

    return true;
}


// USING DFS - O(N)
int check(TreeNode *root)
{

    if(root==NULL) return 0;

    // here we will use the height of binary tree function, so if the tree is balanced, we will return the height of binary tree
    // otherwise it will return -1
    int lh=check(root->left);
    if(lh==-1) return -1;
    int rh=check(root->right);
    if(rh==-1) return -1;
    // the concept is the we will get down calculating the height of every node recursively,
    // we will get a left sub height and a right sub height for us, and we will return max of these
    // instead of returning, we will first check if the difference is greater than 1 or not
    // if it is, we can see that we got a unbalanced tree here
    if(abs(lh - rh) > 1) return -1;

    return 1+max(lh, rh);
}
bool isBalanced(TreeNode *root)
{
    return check(root)!=-1;
}
int main()
{
}

int balanced(TreeNode *root){
    if(!root) return 0;
    
}