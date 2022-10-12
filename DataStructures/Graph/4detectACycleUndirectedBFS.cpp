#include <bits/stdc++.h>
using namespace std;
bool checkforCycle(int s, vector<int> &vis, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({s, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push({it, node});
            }
            else if (it != par)
            {
                return true;
            }
        }
    }
    return false;
}
bool iscycle(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (checkforCycle(i, vis, adj))
                return true;
        }
        return false;
    }
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