/*
Given a binary tree and a leaf node from this tree. It is known that in 1s all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on. The task is to find the minimum time required to burn the complete binary tree.
Examples:


Input :
            1
       /       \
      2          3
    /  \          \
   4    5          6
      /   \         \
     7     8         9
                      \
                       10
Leaf = 8
Output : 7
Initially 8 is set to fire at 0th sec.
            1
       /       \
      2          3
    /  \          \
   4    5          6
      /   \         \
     7     F         9
                      \
                       10
After 1s: 5 is set to fire.
            1
       /       \
      2          3
    /  \          \
   4    F          6
      /   \         \
     7     F         9
                      \
                       10
After 2s: 2, 7 are set to fire.
            1
       /       \
      F          3
    /  \          \
   4    F          6
      /   \         \
     F     F         9
                      \
                       10
After 3s: 4, 1 are set to fire.
            F
       /       \
      F          3
    /  \          \
   F    F          6
      /   \         \
     F     F         9
                      \
                       10
After 4s: 3 is set to fire.
            F
       /       \
      F          F
    /  \          \
   F    F          6
      /   \         \
     F     F         9
                      \
                       10
After 5s: 6 is set to fire.
            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         9
                      \
                       10
After 6s: 9 is set to fire.
            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         F
                      \
                       10
After 7s: 10 is set to fire.
            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         F
                      \
                       F
It takes 7s to burn the complete tree.*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *res = NULL;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(Node *root, int target)
{
    // Your code goes here
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}