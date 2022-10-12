/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]*/
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
// it has a basic method
void findAllPaths(TreeNode *root, vector<string> &ans, string s)
{
    if (root == NULL)
        return;

    // if string is empty, it means we are entering the first character and therefore don't need the arrow
    if (s.empty())
    {
        s += to_string(root->val);
    }
    else
    {
        // when we are between, we put arrow in the string and put value in the string
        s += "->";
        s += to_string(root->val);
    }

    // if doesn't have any element on left and right, it means it's a leaf, so push the string in the vector
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(s);
        s = "";
    }

    // here we are using recursion, to check all the possible sides- left and right
    // if the side is not null, we are going in that direction
    if (root->left)
        findAllPaths(root->left, ans, s);
    if (root->right)
        findAllPaths(root->right, ans, s);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string s = "";
    if (root == NULL)
        return ans;
    findAllPaths(root, ans, s);
    return ans;
}