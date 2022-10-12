/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.
For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \
                 10       14

For the above tree the output should be 5 10 4 14 25.*/
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
vector<int> TopView(TreeNode *root)
{
    // so we made use of map here, and like the previous question, we did level order traversal
    // we had a queue which has col number as its first element, so it get sorted while the value is being input
    // in top view we needed first element appeared in a certain column, so we checked if this col already occured or not
    // but now we need last, so didn't check for that condition
    map<int, int> mp;
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<int, TreeNode *>> q;
    q.push({0, root});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.second;
        int col = p.first;
        mp[col] = node->val;
        if (node->left)
            q.push({col - 1, node->left});
        if (node->right)
            q.push({col + 1, node->right});
    }
    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}
int main()
{
}