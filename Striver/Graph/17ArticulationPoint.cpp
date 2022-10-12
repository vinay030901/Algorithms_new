/*An articulation point (or cut vertex) is defined as a vertex which, when removed along with associated edges,
makes the graph disconnected (or more precisely, increases the number of connected components in the graph).\

observation regarding articulation point and bridge --

1. end points if a bridge will be an articulation point  if that node has degree of at least 2.
2. it is not necessary for an articulation point to be an end point of a bridge.
3. finding bridges algorithm cannot be used to find the articulation point.


Algorithm
Pick an arbitrary vertex of the graph  and run depth first search from it. Note the following fact (which is easy to prove):

Let's say we are in the DFS, looking through the edges starting from vertex . If the current edge  is such that none of the vertices  or its descendants in the DFS traversal tree has a back-edge to any of ancestors of , then  is an articulation point. Otherwise,  is not an articulation point.

Let's consider the remaining case of . This vertex will be the point of articulation if and only if this vertex has more than one child in the DFS tree.

Now we have to learn to check this fact for each vertex efficiently. We'll use "time of entry into node" computed by the depth first search.

So, let  denote entry time for node . We introduce an array  which will let us check the fact for each vertex .  is the minimum of , the entry times  for each node  that is connected to node  via a back-edge  and the values of  for each vertex  which is a direct descendant of  in the DFS tree:

 
 
Now, there is a back edge from vertex  or one of its descendants to one of its ancestors if and only if vertex  has a child  for which . If , the back edge comes directly to , otherwise it comes to one of the ancestors of .

Thus, the vertex  in the DFS tree is an articulation point if and only if .

Implementation
The implementation needs to distinguish three cases: when we go down the edge in DFS tree, when we find a back edge to an ancestor of the vertex and when we return to a parent of the vertex. These are the cases:

 - the edge is part of DFS tree;
 &&  - the edge is back edge to one of the ancestors;
 - the edge leads back to parent in DFS tree.
To implement this, we need a depth first search function which accepts the parent vertex of the current node.



https://cp-algorithms.com/graph/cutpoints.html */

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int par, vector<int> &in, vector<int> &low, vector<int> &vis, int timer, vector<int> adj[])
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    int children = 0;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        if (!vis[it])
        {
            dfs(it, node, in, low, vis, timer, adj); // forward edge
            low[node] = min(low[node], low[it]);
            if (low[it] > in[node] and par != -1) // parent shouldn't be -1 as root isn't articulation point, we will check if root
                                                  // is articulation point or not later, if the root has two or more subtree, it an articulation point, else not
                cout << node << " - " << it << " is a bridge" << endl;
            ++children; // to count the number of subtree of node, if root has two or more, then it is cut vertex
        // to test whether an edge is bridge or not
            /*
            we had--- 
            1->2, 2->3, 3->4, 2->4
            so 2->4 is a back edge here, 
            we will compare low time of 4 to in time of 3
            low time of 4 is in time of 3, so it is not a bridge
            since the above condition indicates that the 4 is connected to ancestor of 3, and therefore removing the connection between
            them will do no harm*/}
            else
                low[node] = min(low[node], in[it]); // if we find another low ancestor, we will change the low value
    }
    if(par==-1 and children>1) cout<<"root is articulation point.\n";
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

    // we have two arrays, in and low, in will store the time in which we enter the node,
    // at node 1 the value is zero, and suppose we enter the node 2 next, then the value at node 2 is 1
    // so its obvious that if two nodes are at same path, then the one with lower in time is ancestor of the one with higher
    // low indicates the lowest ancestor or something which can reach directly to the node
    vector<int> in(n + 1, -1), low(n + 1, -1);
    vector<int> vis(n + 1, 0);
    int timer = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, -1, in, low, vis, timer, adj);
    for (int i = 1; i <= n; i++)
        cout << low[i] << " ";

    // to test whether an edge is bridge or not
    /*
    we had---
    1->2, 2->3, 3->4, 2->4
    so 2->4 is a back edge here,
    we will compare low time of 4 to in time of 3
    low time of 4 is in time of 3, so it is not a bridge
    since the above condition indicates that the 4 is connected to ancestor of 3, and therefore removing the connection between
    them will do no harm*/
}
