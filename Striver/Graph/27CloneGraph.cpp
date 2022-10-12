/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the
second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of
a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned
graph.


Example 1:

https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
/*this question is basic dfs, with some extra dose of linkedlist. As we need to traverse the adjacent nodes and then link
to our answer rather than directly going into the adjacent list(did in basic dfs)

*/
class Solution
{
public:
    Node *dfs(unordered_map<Node *, Node *> &mp, Node *node)
    {
        // first we made the clone value of our node, and declared the neighbors vector
        // we will push that into the map with the same node value we got
        // we then traverse the neighbors vector, if the element is already in map, then we will directly push it
        // and if it isn't, then we call dfs
        Node *clone = new Node(node->val);
        vector<Node *> v;
        mp[node] = clone;
        for (auto it : node->neighbors)
        {
            if (mp.find(it) != mp.end())
                v.push_back(mp[it]);
            else
                v.push_back(dfs(mp, it));
        }
        clone->neighbors = v;
        return clone;
    }
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        if (node->neighbors.size() == 0)
        {
            Node *clone = new Node(node->val);
            return clone;
        }
        unordered_map<Node *, Node *> mp;
        return dfs(mp, node);
    }
};
int main()
{
}