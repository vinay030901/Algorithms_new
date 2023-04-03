#include <bits/stdc++.h>
using namespace std;
vector<int> breadthFirstSearch(int V, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
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
    cout << "breadthFirstSearch: ";
    vector<int> bfs = breadthFirstSearch(n, adj);
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
}