/*Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]


Constraints:

The number of nodes in the tree is in the range [0, 104].
-104 <= Node.val <= 104
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// the solution comprises of travelling to right first, get a sum and then travel to left
// more like preorder but with presum
class Solution
{
public:
    void modifyBst(TreeNode *root, int &sum)
    {
        if (root->right)
            modifyBst(root->right, sum);
        sum += root->val;
        root->val = sum;
        if (root->left)
            modifyBst(root->left, sum);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        if (root)
            modifyBst(root, sum);
        return root;
    }
};
int main()
{
    // Your code here
    return 0;
}