/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file
or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization
algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be
deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree.
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
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

// Encodes a tree to a single string.

// so we use level order traversal for our process
// we created a queue and put the element in the string
// if it is null we used # for it, and we sepatate everything by a comma
string serialize(TreeNode *root)
{
    string str = "";
    if (!root)
        return str;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        // if null, append #, and if not null, append element and comma
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
            str.append("#,");
        else
            str.append(to_string(node->val) + ",");
        if (node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << str;
    return str;
}

// Decodes your encoded data to tree.
// deserialize is done using stringstream here
TreeNode *deserialize(string data)
{
    int size = data.size();
    if (size == 0)
        return NULL;
    stringstream s(data); // we put our string in stringstream
    string str;
    getline(s, str, ',');                     // get line is used to jump over the delimiter(',' in our case) and get the other object
    TreeNode *root = new TreeNode(stoi(str)); // we created the root here
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        // here we process all the element one by one, the root is processed and the left and child are pushed in queue
        // if they are not null, if null,we make that null in our queue
        getline(s, str, ',');
        if (str == "#")
            node->left = NULL;
        else
        {
            TreeNode *l = new TreeNode(stoi(str));
            node->left = l;
            q.push(l);
        }
        getline(s, str, ',');
        if (str == "#")
            node->right = NULL;
        else
        {
            TreeNode *r = new TreeNode(stoi(str));
            node->right = r;
            q.push(r);
        }
    }
    return root;
}