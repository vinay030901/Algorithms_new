/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]-> means 1 right is 2, 2 right is 3, 3 right is 4, 4 right is 5 and 5 right is 6
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]*/

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
TreeNode *pre = NULL;
void flatten(TreeNode *root)
{
    if (root == NULL)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = pre;
    root->left = NULL;
    pre = root;
}