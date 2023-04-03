/*
You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge
in the graph into a chain of nodes, with the number of new nodes varying between each edge.

The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi
in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you
will not subdivide the edge.

To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and
the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].

In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is
maxMoves or less.

Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.

Example 1:
https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/01/origfinal.png
Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
Output: 13
Explanation: The edge subdivisions are shown in the image above.
The nodes that are reachable are highlighted in yellow.
Example 2:

Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
Output: 23
Example 3:

Input: edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
Output: 1
Explanation: Node 0 is disconnected from the rest of the graph, so only node 0 is reachable.*/

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
/*Intuition:

Since we have nodes in between, and want to calculate the reachable ones.
The first thing that comes to mind is how many nodes we can actually reach?
We know, edges=nodes+1
So now if we take 0->1 with 10 nodes in between
We can deduce that distance from 0 to 1 is 11.

Using this, we can initially calculate the minimum distance to reach each node from source , assuming the nodes in between as weights => Djikstra Algorithm

Once calculated minimum distance to reach each node, simply check if this distance<=maxMoves allowed

Now comes the tricky part - How to check how many nodes in between can be visited?

Count the number of nodes reachable on edge e from e[0] and from e[1]
using Extra Distance left=maxMoves-Dist covered by e[1] or e[0]*/
int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
{
    vector<vector<pii>> adj(n);
    int m = maxMoves;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    priority_queue<pii, vector<pii>, greater<pii>> mn;
    mn.push({0, 0});
    vector<int> d(n, 1e8);
    d[0] = 0;
    while (!mn.empty())
    {
        int dist = mn.top().first;
        int node = mn.top().second;
        mn.pop();
        for (auto it : adj[node])
        {
            if (d[it.first] > dist + it.second + 1) // since number of edges=nodes in between+1
            {
                d[it.first] = dist + it.second + 1;
                mn.push({d[it.first], it.first});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) // add 1 for nodes that can be visited
        if (d[i] <= m)
            ans++;

    /*
 Now add for intermediate newly added nodes
 Eg. 0->1 and 10 in between

 Visitable from 0 -> maxMoves-(dist/moves already covered by 0 (from source))
 Visitable from 1 -> maxMoves-(dist/moves already covered by 1 (from source))

 To calculate Extra nodes I can visit we follow above
 */

    for (auto i : edges)
    {
        int src = i[0], dest = i[1], between = i[2];
        int x = max(0, (maxMoves - d[src]));  // nodes visited using edge e[0]->e[1]
        int y = max(0, (maxMoves - d[dest])); // nodes visited using edge e[1]->e[0]
        ans += min(between, x + y);           // minimum to avoid overlapping in counting
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " --> ";
        for (auto x : adj[i])
            cout << "(" << x.first << " , " << x.second << ") ";
        cout << "\n";
    }
    cout << reachableNodes()
}