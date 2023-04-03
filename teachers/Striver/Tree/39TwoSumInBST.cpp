/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST
such that their sum is equal to the given target.

Example 1:
https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false*/

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


// brute force approach is to find the inorder and then use simple two pointer approach if there are two number whose sum is equal to k
vector<int> inorder;
void findInorder(TreeNode *root)
{
    if (root == NULL)
        return;
    findInorder(root->left);
    inorder.push_back(root->val);
    findInorder(root->right);
}
bool findTarget(TreeNode *root, int k)
{
    if (!root->left && !root->right)
        return false;
    findInorder(root);
    int n = inorder.size();
    for (int i = 0, j = n - 1; i != j;)
    {
        int sum = inorder[i] + inorder[j];
        if (k == sum)
            return true;
        else if (k > sum)
            i++;
        else
            j--;
    }
    return false;
}

// the next approach is regarding the same 2 sum concept of two pointers
// we will have a pointer on the smallest element and we will have pointer on the largest element in the bst
// if the key is greater, we will increase the value of smallest element and if the key is lower, then we will 
// decrease the value of greater pointer

// all of this will be done using bst iterator

class BSTIterator
{
public:
    stack<TreeNode *> s;
    // reverse=true -> before
    // reverse=false -> next
    bool reverse=true;
    void pushAll(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            if(reverse) root=root->right;
            else root = root->left;
        }
    }
    BSTIterator(TreeNode *root,bool isReverse)
    {
        reverse=isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *node = s.top();
        s.pop();
        if(reverse)
            pushAll(node->left);
        else if(!reverse) pushAll(node->right);
        return node->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false); // for next
        BSTIterator r(root,true); // for before
        
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            int sum=i+j;
            if(sum==k) return true;
            else if(sum<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};