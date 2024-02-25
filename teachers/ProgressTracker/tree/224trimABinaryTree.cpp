/*Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.



Example 1:


Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
Example 2:


Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]


Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
The value of each node in the tree is unique.
root is guaranteed to be a valid binary search tree.
0 <= low <= high <= 104*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// this is my solution
class Solution
{
public:
    void recur(TreeNode *root, int low, int high)
    {
        if (!root)
            return;
        if (root->left)
        {
            if (root->left->val >= low)
            {
                recur(root->left, low, high);
            }
            else
            {
                root->left = root->left->right;
                recur(root, low, high);
            }
        }
        if (root->right)
        {
            if (root->right->val <= high)
                recur(root->right, low, high);
            else
            {
                root->right = root->right->left;
                recur(root, low, high);
            }
        }
    }
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        int f = 0;
        while (root)
        {
            if (root->val < low)
            {
                root = root->right;
                f = 1;
            }
            if (root->val > high)
            {
                root = root->left;
                f = 1;
            }
            if (f == 0)
                break;
            f = 0;
        }
        recur(root, low, high);
        return root;
    }
};

// online solution
/*Before we get to the algorithm, let's clarify our task:

We have binary search tree. Variable root is pointer to the tree root.
We have boundaries [L..R]
We need to trim our tree so that all elements fit into boundaries [L..R]
Algorithm
Binary search tree stores a list of numbers in sorted format:

Parent > all left children
Parent < all right children.*/
TreeNode *trimBST(TreeNode *root, int L, int R)
{
    if (!root)
        return root;
    if (root->val >= L && root->val <= R)
    {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
    if (root->val < L)
        return trimBST(root->right, L, R);
    return trimBST(root->left, L, R);
}
int main()
{
    // Your code here
    return 0;
}