/*
JENNNY OR CODENCODE LECTURE
a bridge is defined as an edge which when removed makes graph disconnected or more precisely it increases the number of connected
compononents

dfs tree: when we make a dfs call, we look at its adjacency list, if it is not visited, we call dfs on that

when we are traversing the graph, some edges are not visited, these are those edges which are creating the cycle
or pointing to that adjacent node which is already visited
so these edges are called back edges
and the other edges which are traversed are called forward edges

each back edge creates a cycle,
important- every back edge connects to a node which is not its direct parent
and back edges can never be bridges, even if we remove those back edges, the graph is still connected*/

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int par, vector<int> &in, vector<int> &low, vector<int> &vis, int timer, vector<int> adj[])
{
    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        if (!vis[it])
        {
            dfs(it, node, in, low, vis, timer, adj); // forward edge
            low[node] = min(low[node], low[it]);
            if (low[it] > in[node])
                cout << node << " - " << it << " is a bridge" << endl;
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
                low[node] = min(low[node], in[it]);
    }
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