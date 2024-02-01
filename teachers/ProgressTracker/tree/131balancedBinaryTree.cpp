/*
Given a binary tree, determine if it is
height-balanced
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104*/
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
class Solution
{
public:
    bool ans = true;
    int depth(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = depth(node->left);
        int right = depth(node->right);
        if (abs(left - right) > 1)
        {
            ans = false;
            return 0;
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        int m = depth(root);
        return ans;
    }
};
int main()
{
    // Your code here
    return 0;
}