/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q
as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.*/

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

// we have two methods for this- first the easy one but with O(2N) TIME AND O(2N) SPACE
// by finding the path of p and q, and then checking till they are same.

// here, we first find the path of both p and q using these two function below
vector<TreeNode *> pPath, qPath;
bool findPPath(TreeNode *root, TreeNode *p)
{
    if (root == NULL)
        return false;
    pPath.push_back(root);
    if (root == p) // if we reach p, we return true and answer will return true, otherwise we pop_back the vector
        return true;
    if (findPPath(root->left, p) || findPPath(root->right, p))
        return true;
    pPath.pop_back();
    return false;
}
// finding the path of q now
bool findQPath(TreeNode *root, TreeNode *q)
{
    if (root == NULL)
        return false;
    qPath.push_back(root);
    if (root == q)
        return true;
    if (findQPath(root->left, q) || findQPath(root->right, q))
        return true;
    qPath.pop_back();
    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // now we got both paths, we will traverse till both are same, means if they followed the same path in tree.
    // and the time we get different nodes, we will break and then return ans
    bool b = findPPath(root, p);
    b = findQPath(root, q);
    TreeNode *ans = pPath[0];
    for (int i = 1; i < min(pPath.size(), qPath.size()); i++)
    {
        if (pPath[i] == qPath[i])
            ans = pPath[i];
        else
            break;
    }
    return ans;
}

// we will use a traversal technique for doing it in O(N) time and constant space
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // what we do here is move in the tree and if we find other p and q, we will return the node
    // so when any node will get both p and q from different sides, it will return its own value and we will get the LCA

    if (root == NULL || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root; // if both are not null, we will return root
}