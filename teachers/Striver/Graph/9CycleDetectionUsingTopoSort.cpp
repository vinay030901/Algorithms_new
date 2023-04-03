/* a topo sort is defined as the linear ordering of vertices such that if there is an edge u->v, then u appears before v in
that ordering

topological sort is for directed acyclic graph only*/

#include <bits/stdc++.h>
using namespace std;

/*
we need to detect cycle in a graph
we know that toposort can only be used for directed acyclic graph, so any graph other than that will not give the toposort
so we are using reverse logic here
if the graph has cycle, we won't be able to find toposort, and if it doesn't have cycle, we will be.
*/

bool topoSort(int n, vector<int> adj[])
{
    vector<int> indegree(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
        for (auto it : adj[i])
            indegree[it]++;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    // we know that if a topological sort is generated, the number of nodes will be equal to n, since topo sort is linear ordering of vertices
    if (cnt == n)
        return false;
    return true;
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
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto x : adj[i])
            cout << " --> " << x;
        cout << "\n";
    }
    if (topoSort(n, adj))
        cout << "cycle is present";
    else
        cout << "cycle is not present";
}