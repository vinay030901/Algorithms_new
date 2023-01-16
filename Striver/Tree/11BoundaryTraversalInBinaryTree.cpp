/*
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. The boundary includes left
boundary, leaves, and right boundary in order without duplicate nodes. (The values of the nodes may still be duplicates.)
The left boundary is defined as the path from the root to the left-most node. The right boundary is defined as the path from
the root to the right-most node. If the root doesn’t have left subtree or right subtree, then the root itself is left boundary
or right boundary. Note this definition only applies to the input binary tree, and not apply to any subtrees.
The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if it exists.
If not, travel to the right subtree. Repeat until you reach a leaf node.
The right-most node is also defined in the same way with left and right exchanged.
For example, boundary traversal of the following tree is “20 8 4 10 14 25 22”
 */
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
vector<int> ans;
void ReadLeft(TreeNode *root)
{
    if (root == NULL)
        return;
    if (root->left) // so if we have a node present at the left side, we will add it in our ans
    // this is printing in top down manner
    {
        ans.push_back(root->val);
        ReadLeft(root->left);
    }
    else if (root->right) // we can also find the element in the right side of the node if there is no left side
    {
        ans.push_back(root->val);
        ReadLeft(root->right);
    }
    return;
}

void ReadRight(TreeNode *root)
{
    if (root == NULL)
        return;
    if (root->right)
    {
        ReadRight(root->right); // is is similar as readleft but the approach is bottom up rather than top down manner
        // we first reach the point where the next node leads to NULL and then go back and add the element in our ans
        ans.push_back(root->val);
    }
    else if (root->left)
    {
        ReadRight(root->left);
        ans.push_back(root->val);
    }
    return;
}
void ReadLeaves(TreeNode *root)
{
    if (root == NULL)
        return;
    ReadLeaves(root->left);
    if (!root->left && !root->right)
    {
        ans.push_back(root->val);
    }
    ReadLeaves(root->right);
}
vector<int> BoundaryTraversal(TreeNode *root)
{
    if (root == NULL)
        return ans;

    /*
    We break the problem in 3 parts:
    1. Print the left boundary in top-down manner.
    2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
    …..2.1 Print all leaf nodes of left sub-tree from left to right.
    …..2.2 Print all leaf nodes of right subtree from left to right.
    3. Print the right boundary in bottom-up manner.
    We need to take care of one thing that nodes are not printed again. e.g. The left most node is also the leaf node of the tree.*/

    ans.push_back(root->val); // printing the root node
    ReadLeft(root->left);     // printing the left side

    // taking the elements from both sides- left and right
    ReadLeaves(root->left);
    ReadLeaves(root->right);

    // reading the right side of the tree
    ReadRight(root->right);
}
int main()
{
}