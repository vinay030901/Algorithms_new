/*A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.



Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]


Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.*/
#include <bits/stdc++.h>
using namespace std;
/*"Basic idea: the roots of MHT must be the mid points of the longest leaf to leaf path in the tree.
And to find the longest path, we can first find the farthest leaf from any node, and then find
the farthest leaf from the node found above. Then these two nodes we found are the end points
of the longest path. And last, we find the centers of the longest path."

Steps:

1.Create adjcent list(neighbors)

2.Count in-degree of all vertices.

3.Pick any vertex 'v' which has in-degree of 0.

4.Print 'v'. Remove the vertex 'v' and all edges coming out of it. Decrement in-degrees of all neighbors of vertex 'v' by 1.

5.Repeat steps 3 and 4 till u either have just 1 or 2 nodes available.*/
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 0)
        return {};
    if (n == 1)
        return {0};
    vector<int> adj[n], degree(n, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 1)
            q.push(i);
    vector<int> ans;
    while (!q.empty())
    {
        int size = q.size();
        ans.clear();
        while (size--)
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto it : adj[node])
            {
                degree[it]--;
                if (degree[it] == 1)
                    q.push(it);
            }
        }
    }
    return ans;
}
int main()
{
    // Your code here
    return 0;
}