/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order
traversal when next() is called.

Example 1:
https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png

Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False*/

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

class BSTIterator
{
public:
    // the first method is basic, we put all the node value in vector using inorder
    // then return the value if next is called, and return if we are at last, when has next is calles
    vector<int> inorder;
    int i = 0;
    void findInorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        findInorder(root->left);
        inorder.push_back(root->val);
        findInorder(root->right);
    }
    BSTIterator(TreeNode *root)
    {
        inorder.push_back(-1);
        findInorder(root);
    }

    int next()
    {
        return inorder[++i];
    }

    bool hasNext()
    {
        int s = inorder.size();
        if (i == s - 1)
            return false;
        else
            return true;
    }
};

// the second method make use of stack here
// it is like inorder traversal, but using stack only
// we push all the left element in the stack, so the leftmost element will be at top
// when the next is called, we return the leftmost and then push all the elements in the right of that left into the stack
// the pushed elements are less than element above, so it works like that
// for hasNext, we return if stack is empty
class BSTIterator
{
public:
    stack<TreeNode *> s;
    void pushAll(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *node = s.top();
        s.pop();
        pushAll(node->right);
        return node->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};
