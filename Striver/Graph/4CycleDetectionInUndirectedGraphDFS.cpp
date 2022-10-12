#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int par, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, node, adj, vis))
                return true;
        }
        else if (it != par)
            return true;
    }
    return false;
}
bool detectCycle(vector<int> adj[], int n)
{
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis))
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
        adj[b].push_back(a);
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