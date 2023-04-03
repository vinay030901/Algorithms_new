#include <bits/stdc++.h>
using namespace std;
bool checkforCycle(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            if (checkforCycle(it, node, vis, adj))
            {
                return true;
            }
            else if (it != parent)
                return true;
    }
    return false;
}
bool isCycle(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkforCycle(i, -1, vis, adj))
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto x : adj[i])
        {
            cout << "->" << x;
        }
        cout << endl;
    }
}