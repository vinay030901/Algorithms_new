/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1)
respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost
column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these
nodes by their values.

Return the vertical order traversal of the binary tree.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
Example 3:

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.*/
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
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // in this map: the first is col number, then inside it, we have map, where first is row number and then multiset

    // the thing is we will work on it like level order traversal, but in queue, we will also push the col and row.
    // if we are moving left, col decrease and if we are moving right, col increase, row increase when we go down

    map<int, map<int, multiset<int>>> nodes; // to store vertical orders
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode *, pair<int, int>>> q;
    vector<pair<int, int>> v;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.first;
        int x = p.second.first, y = p.second.second; // x and y are col number and row number
        nodes[x][y].insert(node->val);               // inserting the value in nodes
        if (node->left)
            q.push({node->left, {x - 1, y + 1}});
        if (node->right)
            q.push({node->right, {x + 1, y + 1}});
    }

    // putting the values in ans is interesting, we will traverse in the nodes, that is from low to high
    // they become low to high due to map data structure we took earlier.
    for (auto p : nodes)

    {
        vector<int> level;
        // then we push every element in that column in ans,
        for (auto q : p.second)                                          // here we are traversing the innner map
            level.insert(level.end(), q.second.begin(), q.second.end()); // push all the element of multiset,
        // if row and col are same, value is sorted due to multiset
        ans.push_back(level);
    }
    return ans;
}
int main()
{
}