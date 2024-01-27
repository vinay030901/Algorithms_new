/*Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1*/
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
// https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
//  nth catalan number
int memo[20][20];
int cal(int st, int end)
{
    if (st >= end)
        return 1;
    if (memo[st][end] != 0)
        return memo[st][end];
    int ans = 0;
    for (int root = st; root <= end; root++)
    {
        ans += cal(st, root - 1) * cal(root + 1, end);
    }
    return memo[st][end] = ans;
}

int numTrees(int n)
{
    return cal(1, n);
}