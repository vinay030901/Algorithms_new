/*
Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST).
If the complete Binary Tree is BST, then return the size of the whole tree.
Examples:


Input:
      5
    /  \
   2    4
 /  \
1    3

Output: 3
The following subtree is the
maximum size BST subtree
   2
 /  \
1    3


Input:
       50
     /    \
  30       60
 /  \     /  \
5   20   45    70
              /  \
            65    80
Output: 5
The following subtree is the
maximum size BST subtree
      60
     /  \
   45    70
        /  \
      65    80*/

/*

GEEKS FOR GEEKS

Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
          /   \
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2
Output: 2
Explanation: The following sub-tree is a
BST of size 2:
       2
    /    \
   N      8
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
// the brute force approach is to first go to all nodes, check if the bst is valid from it and if it is, we count the number
// of nodes in it, we will have a max counter for this and in last we will return last
// in leetcode, instead of counting the number of nodes, we will find the sum of nodes

// basic soluiton which is n^2
/*  bool ans = true;
long long prev = -2157483648, next;
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    next = root->data;
    if (next > prev)
    {
        prev = next;
    }
    else
    {
        ans = false;
        return;
    }
    inorder(root->right);
}
bool isValidBST(Node *root)
{
    inorder(root);
    prev = -2157483648;
    bool a = ans;
    ans = true;
    return a;
}
void count(Node *root, int &sum)
{
    if (root == NULL)
        return;
    count(root->left, sum);
    sum += 1;
    count(root->right, sum);
}
int countNodes(Node *root)
{
    int sum = 0;
    count(root, sum);
    return sum;
}
int maxSumBST(Node *root)
{
    int mx = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (isValidBST(node))
            {
                int ans = countNodes(node);
                mx = max(ans, mx);
                cout<<mx<<endl;
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return mx;
}
int largestBst(Node *root)
{
    return maxSumBST(root);
}*/
class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solution
{
public:
    NodeValue helper(TreeNode *root)
    {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);
        NodeValue left = helper(root->left);
        NodeValue right = helper(root->right);

        if (left.maxNode < root->val and root->val < right.minNode)
        {
            // it is a valid bst
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }

        // if it isn't a valid bst
        // given such a range that they never be compared
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    int largestBSTSubtree(TreeNode *root)
    {
        return helper(root).maxSize;
    }
};