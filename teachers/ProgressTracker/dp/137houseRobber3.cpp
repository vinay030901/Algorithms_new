/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.



Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.


Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};
int rec(TreeNode *root, int &l, int &r)
{
    if (!root)
        return 0;
    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = rec(root->left, ll, lr);
    r = rec(root->right, rl, rr);
    return max(l + r, root->val + ll + lr + rl + rr);
}
int rob(TreeNode *root)
{
    int l = 0, r = 0;
    return rec(root, l, r);
}
int main()
{
    // Your code here
    return 0;
}