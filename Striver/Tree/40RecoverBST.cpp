/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped
by mistake. Recover the tree without changing its structure.

Example 1:
https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*/

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

// first method is extreme brute force, we first find the inorder of bst, then we take a new vector equal to inorder
// and sort it, so we will have values at proper positions
// then we check for improper two values and swap those
vector<TreeNode *> v;
void findInorder(TreeNode *root)
{
    if (root == NULL)
        return;
    findInorder(root->left);
    v.push_back(root);
    findInorder(root->right);
}
void recoverTree(TreeNode *root)
{
    findInorder(root);
    vector<TreeNode *> c = v;
    sort(c.begin(), c.end(), [&](TreeNode *a, TreeNode *b)
         { return a->val < b->val; });
    int f = 0;
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    for (int i = 0; i < v.size(); i++)
        if (v[i]->val != c[i]->val)
        {
            if (f == 0)
            {
                f = 1;
                first = v[i];
            }
            else
                second = v[i];
        }
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
}


// our next approach is using inorder traveral too
// what we do is in the inorder traversal, we will check the condition if previous is greater than present root
// if it is, we give values to them whether we find this condition for first time or second time
// then we swap the values
vector<TreeNode *> v;
TreeNode *prev = NULL, *violation1 = NULL, *violation2 = NULL;
void findInorder(TreeNode *root)
{
    if (root == NULL)
        return;
    findInorder(root->left);
    if (prev != NULL and prev->val > root->val)
    {
        if (violation1 == NULL)
            violation1 = prev;
        violation2 = root;
    }
    prev = root;
    findInorder(root->right);
}
void recoverTree(TreeNode *root)
{
    findInorder(root);
    int temp = violation1->val;
    violation1->val = violation2->val;
    violation2->val = temp;
}