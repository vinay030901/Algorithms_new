/* in bfs, we travel to the adjacent nodes first and then we travel to the child of those nodes*/
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int n)
{
    vector<int> ans;
    vector<int> vis(n + 1, 0);   // we mark a visited matrix for us
    for (int i = 1; i <= n; i++) // this loop would be used, when we don't have a single connected component in our graph
    {
        if (!vis[i])
        {
            queue<int> q; // we always use a queue in bfs traversal
            q.push(i);
            vis[i] = 1; // mark the element as visited
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto x : adj[node])
                {
                    if (!vis[x]) // this is an important part, if not done, our graph will be in a cycle and give tle
                    {
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
        }
    }
    return ans;
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
    cout << "breadth first search: ";
    vector<int> b = bfs(adj, n);
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
}
