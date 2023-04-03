/*
Given a binary tree, write a function that returns true if the tree satisfies below property.
For every node, data value must be equal to sum of data values in left and right children.
Consider data value as 0 for NULL children. Below tree is an example

Input:
     10
    /
  10
Output: 1
Explanation: Here, every node is sum of its left and right child.
Example 2:

Input:
       1
     /   \
    4     3
   /  \
  5    N
Output: 0
Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of
root node. Hence, this tree does not satisfy the given conditions.*/
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
int isSumProperty(TreeNode *root)
{
  int sum = 0;
  if (!root || (!root->left && !root->right))
    return 1;
  if (root->left)
    sum += root->left->val;
  if (root->right)
    sum += root->right->val;
  return (sum == root->val) && isSumProperty(root->left) && isSumProperty(root->right);
}

// we need to convert the binary tree to a tree which follows the children sum property
// for this we can increase the value the value of the nodes any number of times

// so to convert this, we will do the process in O(n) time
// since we can add any value to the node, instead of traversing and changing the value from leaves
// we will go from root, then compare it with its childs, and copy the higher value in the children nodes, whether
// it is the sum of children or the value of the root
/* ex-
              40
                              40

        10         20       -->             40          70

    2       5   30    40                 40     40  30      40

now we traverse from end
and change the value of the parents
                                                  |
                                                  |
                                                 \ /
                                                 150

                                            80         70

                                          40   40   30      40*/

void childrenSumProperty(TreeNode *root)
{
  if (root == NULL)
    return;
  int sum = 0;
  if (root->left)
    sum += root->left->val;
  if (root->right)
    sum += root->right->val;
  if (sum > root->val)
    root->val = sum;
  else
  {
    if (root->left)
      root->left->val = root->val;
    if (root->left)
      root->left->val = root->val;
  }

  childrenSumProperty(root->left);
  childrenSumProperty(root->right);

  int tot = 0;
  if (root->left)
    tot += root->left->val;
  if (root->right)
    tot += root->right->val;
  if (root->left || root->right)
    root->val = tot;
}