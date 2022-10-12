#include <bits/stdc++.h>
using namespace std;
// in this method, we mark the parents of the nodes with the elements too
// what we do is traverse through the graph and also mark the parent of them, we know the fact that
// when we are marking the nodes visited, if there is no cycle, the only nodes which is visited earlier is the parent one
// but if we find another node like this, this means, that node is visited from other side, which shows that it is a cycle
bool detectCycle(vector<int> adj[], int n)
{
    vector<int> vis(n + 1, 0);   // we mark a visited vector for us
    for (int i = 1; i <= n; i++) // this loop would be used, when we don't have a single connected component in our graph
    {
        if (!vis[i])
        {
            queue<pair<int, int>> q; // we always use a queue in bfs traversal
            q.push({i, -1});
            vis[i] = 1; // mark the element as visited
            while (!q.empty())
            {
                int node = q.front().first;
                int par = q.front().second;
                q.pop();
                for (auto it : adj[node])
                {
                    if (!vis[it]) // this is an important part, if not done, our graph will be in a cycle and give tle
                    {
                        q.push({it, node});
                        vis[it] = 1;
                    }
                    else if (it != par)
                    {
                        return true;
                    }
                }
            }
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

bool detectCycle(vector<int> adj[], int n)
{
    vector<int>vis(n,0);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            queue<pair<int,int>>q;
            q.push({i,-1});
            while(!q.empty())
            {
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                vis[node]=1;
                for(auto it:adj[node])
                {
                    if(!vis[it])
                    q.push({it,node});
                    else if(parent!=it)
                    return false;
                }
            }
        }
    }
    return true;
}