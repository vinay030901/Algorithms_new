/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.



Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false


Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool sameTreeOrNot(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 || !root2)
            return root1 == root2;
        return root1->val == root2->val && (sameTreeOrNot(root1->left, root2->left)) && (sameTreeOrNot(root1->right, root2->right));
    }
    bool ans = false;
    void traverse(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return;
        if (root->val == subRoot->val)
        {
            if (sameTreeOrNot(root, subRoot))
            {
                ans = true;
                return;
            }
        }
        traverse(root->left, subRoot);
        traverse(root->right, subRoot);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        traverse(root, subRoot);
        return ans;
    }
};
int main()
{
    // Your code here
    return 0;
}