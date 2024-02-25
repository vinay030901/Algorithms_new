/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

Example 1:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []*/

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

/*for example we have
                8
              /
             5
            /  \
           2    7
suppose we need to delete 5, first we search 5 in the bst, when we find the element, then we have two choice,
1. is to connect 8 to 2 and then 7 is right of 2
2. other is to connect 8 to 7 and 2 is left of 7

we will follow the first approach for now*/

TreeNode *findExtremeRight(TreeNode *root)
{
    // find the extreme right of the tree node, so that we can connect the right side of the node to be deleted to the extreme
    // right of the left of root, in that way the condition of tree will ṇot break up and it remain bst
    while (root->right != NULL)
        root = root->right;
    return root;
}
TreeNode *helper(TreeNode *root)
{
    // these two if condition are for edge cases, where if we don't have any left value for the root, then we just return right
    // and if don't have any right, no need to connect anything to extreme right and we return root left
    if (root->left == NULL)
        return root->right;
    if (root->right == NULL)
        return root->left;

    // now we have extreme right with us
    TreeNode *lastRight = findExtremeRight(root->left);
    TreeNode *rightChild = root->right; // and we have right child
    lastRight->right = rightChild;// we connect extreme right to our right child
    return root->left; // we return root left
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    // if we want to delete the root, we just return root left, and right side would be connected to the extreme right of left subtree
    if (root->val == key)
        return helper(root);
    
    // we will create a dummy node to return the answer
    TreeNode *dummy = root;

    // here we will search for that node and call the helper function using it
    while (root != NULL)
    {
        // so if root val is greater than key, the key is in left side, we call left side and check if the root left is the key
        if (root->val > key)
        {
            // so if we find that root left is key, we will call helper here
            if (root->left != NULL and root->left->val == key)
                root->left = helper(root->left);
            else
                root = root->left;
        }
        // and if the key is bigger, that means the key is in right side
        else
        {
            if (root->right != NULL and root->right->val == key)
                root->right = helper(root->right);
            else
                root = root->right;
        }
    }
    return dummy;
}