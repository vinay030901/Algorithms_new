/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:

Input: root = [3,1,4,null,2], k = 1
https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg
Output: 1
Example 2:

https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3*/

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

// one solution using O(N) complexity is to first take all the value of the bst in vector using inorder traversal
// we know doing inorder traversal of the bst gives us the values in sorted order
// then we return the kth value of the vector
vector<int> v;
void findInorder(TreeNode *root)
{
    if (root == NULL)
        return;
    findInorder(root->left);
    v.push_back(root->val);
    findInorder(root->right);
}
int kthSmallest(TreeNode *root, int k)
{
    findInorder(root);
    return v[k - 1];
}

// other solution which is faster and space efficient is using a counter here, better than 91%
int cnt = 0, ans;
void findInorder(TreeNode *root, int &k)
{
    if (root == NULL)
        return;
    findInorder(root->left, k);
    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }
    findInorder(root->right, k);
}
int kthSmallest(TreeNode *root, int k)
{
    findInorder(root, k);
    return ans;
}

// another solution is to use morris traversal for this, which would be more space efficient as it doesn't take stack space
int getInorder(TreeNode *root, int &k)
{
    int cnt = 0, ans;
    TreeNode *cur = root;
    while (cur)
    {
        if (cur->left == NULL) // no left, so the node is itself the root
        {
            cnt++;
            if (cnt == k)
            {
                ans = cur->val;
            }
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cnt++;
                if (cnt == k)
                {
                    ans = cur->val;
                }
                cur = cur->right;
            }
        }
    }
    return ans;
}
int kthSmallest(TreeNode *root, int k)
{
    int ans = getInorder(root, k);
    return ans;
}
