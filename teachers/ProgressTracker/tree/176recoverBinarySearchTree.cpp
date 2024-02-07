/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1


Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
int main() {
    // Your code here
    return 0;
}