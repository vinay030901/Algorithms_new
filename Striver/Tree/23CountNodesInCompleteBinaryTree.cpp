/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1*/
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
// brute force approach in O(N) time using inorder, we may use postorder, preorder or level order
int cnt=0;
void inorder(TreeNode *root)
{
    if(root==NULL) return;
    cnt++;
    inorder(root->left);
    inorder(root->right);
}
int countNodes(TreeNode* root) {
    inorder(root);
    return cnt;
}

/*
so the formula is 2^height-1, that works only for a perfect tree.

To determine if it is perfect subtree, go all the way to down and count the left nodes and right nodes, if they are equal, it
is a perfect tree, otherwise it is not.

If not a perfect subtree, we go to left subtree and again determine if it is a perfect subtree, and so on

When we have our left and right heights, we do 1+left+right

1<<n is the same as 2^n*/

int findLeftHeight(TreeNode *root)
{
    int h=0;
    while(root)
    {
        h++;
        root=root->left;
    }
    return h;
}
int findRightHeight(TreeNode *root)
{
    int h=0;
    while(root)
    {
        h++;
        root=root->right;
    }
    return h;
}
int countNodes(TreeNode* root) {
    if(root==NULL) return 0;
    int lh=findLeftHeight(root);
    int rh=findRightHeight(root);
    if(lh==rh) return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
}