#include <bits/stdc++.h>
using namespace std;
/*with the help of bellmanford algo, it will tell us if it has negative edge weieghts or not
it is for directed graphs but we can convert it to undirected graphs

algo:
we have to relax the edges n-1 times, that means if dis[u]+wt<dis[v] -> dis[v]=dis[u]+wt.

why n-1 times: the longest path we need to go from one point to another is n-1;
*/

vector<int> bellmanFord(vector<vector<int>> adj, int n, int src)
{
    vector<int> dis(n + 1, INT_MAX);
    dis[src] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj.size(); j++)
        {
            int u = adj[j][0], v = adj[j][1], wt = adj[j][2];
            if (dis[u] + wt < dis[v])
                dis[v] = wt + dis[u];
        }
    }

    for (int j = 0; j < adj.size(); j++)
    {
        int u = adj[j][0], v = adj[j][1], wt = adj[j][2];
        if ((dis[u] + wt < dis[v]) and dis[u] != INT_MAX)
        {
            cout << "negative edge is detected\n";
            return {};
        }
    }
    return dis;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj.insert(adj.end(), {a, b, wt});
    }
    vector<int> ans = bellmanFord(adj, n, 0);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}