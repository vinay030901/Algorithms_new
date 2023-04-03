/*
Given the root of a binary tree, the value of a target node target, and an integer k,
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []
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
/*
notes:
- mark each node to its parents to traverse upwards, you can use map for it
- we then do bfs traversal starting from the target node.
- as long as we have not seen our nodes previously, traverse up,left,right until reached Kth distance
- when reached Kth distance, break out of bfs loop and remaining node's values in our queue is our result
*/
void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, TreeNode *target)
{
    // in this function, we are marking the parents of our nodes
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        // taking every element one by one and checking if they have childs, then making them parents of those childs by pushing in map
        TreeNode *current = q.front();
        q.pop();
        if (current->left)
        {
            parent[current->left] = current;
            q.push(current->left);
        }
        if (current->right)
        {
            parent[current->right] = current;
            q.push(current->right);
        }
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent; // node->parent node
    markParents(root, parent, target);

    unordered_map<TreeNode *, int> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    // now we are traversing all the nodes, both childs and parent
    // we are using a visited vector to check if they are already visited, means we have checked that part of tree
    while (!q.empty())
    {
        int size = q.size();
        // if current level or depth level is k, I will break
        if (curr_level == k)
            break;
        curr_level++;
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left and !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right and !visited[current->right])
            {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent[current] and !visited[parent[current]])
            {
                q.push(parent[current]);
                visited[parent[current]] = true;
            }
        } 
    }
    
    vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front()->val);
        q.pop();
    }
    return result;
}