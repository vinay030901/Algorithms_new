#include <bits/stdc++.h>
using namespace std;
/*the dfs appraoch for undirected graph could not be used for directed graph
we need to use self dfs along with visited graph
so we will visited the graph and mark each element in bfs and dfs array
but when we go back to previous elements, then we mark dfsVis array as unvisited, our visited array will remain same
this will happen with all element until we have an element which have another branch

then we go to second branch and stop at the element from which we previously went back, as we will reach a point where
vis is market but dfsVis is not, it means we went back from there instead of completing the cycle, so this is not a cycle

we will come back and mark every one unvisited in dfsVis

we will do the same for other branches and if we keep on visiting nodes and if reach a condition where an element is visited in both
dfsVis and Vis,we can say that a cycle is present and then, we will return true*/

bool cycleCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
{
    // mark both vis and dfsVis
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it]) // now we traversing all the children
        {
            if (cycleCheck(it, adj, vis, dfsVis)) // and call the function for them, which will mark vis and dfsVis
                return true;
        }
        else if (dfsVis[it]) // if the dfsVis is marked, and vis is marked too, cycle is present
            return true;
    }
    dfsVis[node] = 0; // when we go back, we mark the dfsVis as false
    return false;
}
bool detectCycle(vector<int> adj[], int n)
{
    vector<int> vis(n + 1, 0);
    vector<int> dfsVis(n + 1, 0);
    for (int i = 1; i <= n; i++) // we are traversing the limit
    {
        if (!vis[i])
        {
            if (cycleCheck(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i;
        for (auto x : adj[i])
            cout << " --> " << x;
        cout << "\n";
    }
    if (detectCycle(adj, n))
        cout << "cycle is present in graph.";
    else
        cout << "cycle is not present";
}

bool cycleCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            return cycleCheck(it, adj, vis, dfsvis);
        else if (dfsvis[it] == 1)
            return true;
    }
    dfsvis[node] = 0;
    return false;
}
bool check(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    vector<int> dfsvis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            if (cycleCheck(i, adj, vis, dfsvis))
                return true;
    }
    return false;
}