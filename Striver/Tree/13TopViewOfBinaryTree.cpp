/*
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the
 top view of it. The output nodes can be printed in any order.

A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node
x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \
        4
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6*/
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
        if (mp.find(col) == mp.end())
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