/*Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.



Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1


Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int rec(TreeNode *root, int l, int r)
{
    if (!root)
        return 0;
    TreeNode *left_ptr = root, *right_ptr = root;
    if (!l)
        while ((left_ptr = left_ptr->left))
            l++;
    if (!r)
        while ((right_ptr = right_ptr->right))
            r++;
    if (l == r)
        return (1 << (l + 1)) - 1;
    return 1 + rec(root->left, l - 1, 0) + rec(root->right, 0, r - 1);
}
int countNodes(TreeNode *root)
{
    return rec(root, 0, 0);
}
int main()
{
    // Your code here
    return 0;
}