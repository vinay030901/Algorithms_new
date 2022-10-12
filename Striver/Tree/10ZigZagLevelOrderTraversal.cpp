/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, 
then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []*/
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    // the process here is similar like level order traversa.
    // we use a queue and push the root in it
    // then we first push the elements from left to right
    // we change the direction and now from right to left
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);

    bool leftToRight = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> level(n);
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            // here we are either pushing from left or from right according to the leftToRight 
            int ind = (leftToRight) ? i : (n - i - 1);
            level[ind] = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}
int main()
{
}