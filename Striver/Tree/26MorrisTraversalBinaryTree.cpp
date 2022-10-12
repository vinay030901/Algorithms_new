/*
Using Morris Traversal, we can traverse the tree without using stack and recursion. The algorithm for Preorder is
almost similar to Morris traversal for Inorder.

1...If left child is null, print the current node data. Move to right child.
….Else, Make the right child of the inorder predecessor point to the current node. Two cases arise:
………a) The right child of the inorder predecessor already points to the current node. Set right child to NULL. Move to right
child of current node.
………b) The right child is NULL. Set it to current node. Print current node’s data and move to left child of current node.
2...Iterate until current node is not NULL.

if we have inorder: 4,2,5,6,1,3

                1
              /    \
            2       3
          /  \
        4      5
                \
                 6

so our traversal will be like:
1 -> 2 -> 4, now we go to the parent pointer 2
so 4-> 2 -> 5 -> 6 now we completed the right side, we go the parent of 2, that is 1
so 6 -> 1 -> 3

now let's talk about certain cases:

1st case: if left is NULL, that is, 1->null->2, so instead of going to the left,we go to the root, and then to the right

2nd case: when we reach the extreme right of the left subtree, we go back to root of our treee via the path, if we doesn't have a
thread, we create a thread.

now we traverse the tree again,
1->2->4: 4 doesn't have a left, so we print 4
we now go back to the parent via path, that is 2, now we print 2
2->5: 5 doesn't have a left, so 5 himself is the root, and we print 5.
5->6, 6 doesn't have a left, so 6 himself is the root, and we print 6
now we go to right, but ideally we go to 1 via thread,
1->2: but 2 has already a thread, so don't go to 2.
now 1->3: 3 is root, so print 3*/

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
vector<int> getInorder(TreeNode *root)
{
    vector<int> inorder;
    if (root == NULL)
        return inorder;
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL) // no left, so the node is itself the root
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

vector<int> getPreorder(TreeNode *root)
{
    vector<int> preorder;
    if (root == NULL)
        return preorder;
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL) // no left, so the node is itself the root
        {
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                prev->right = NULL; 
                cur = cur->right;
            }
        }
    }
    return preorder;
}