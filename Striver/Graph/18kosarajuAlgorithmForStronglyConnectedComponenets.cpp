/*A directed graph is strongly connected if there is a path between all pairs of vertices.
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
For example, there are 3 SCCs in the following graph.

https://media.geeksforgeeks.org/wp-content/cdn-uploads/SCC.png

1 -> 2 -> 4
 ^  /     |
  \ ^     `
   3      5

so
from 1 we can go to 2 and 3
2 can go to 3 and 1
3 can go to 1 and 2
so 1,2,3 is a strongly connected component

4 is an scc in itself
and 5 is too

to find the strongest connected component, what we do use is dfs
but not regular dfs
we connect our graph from back, means instead of starting from 1, we will start from 5
so 5-> we can't go anywhere, so it is scc itself
4-> we can't visit 5 because it is already visited and we can't go anywhere
3-> we can go to 1 and 2 and 3
2-> we can go 1 and 3
1-> we can go to 2 and 3

approach----
1. we need to sort the nodes according to finishing time, so we will use toposort for this
we will push the element in the stack using dfs, and we will have the last element at the top

2. we transpose the graph, and all the edges will be reversed, so instead if 1->2 we have 2->1
using this we will not be going anywhere away from scc

3. then we will take the nodes one by one and find the scc
*/

#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, stack<int> &s, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            topoSort(it, s, vis, adj);
    s.push(node);
}
void revdfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    cout << node << " ";
    for (auto it : adj[node])
        if (!vis[it])
            revdfs(it, vis, adj);
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
        cout << i << " --> ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
    stack<int> s;
    vector<int> vis(n+1, 0);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            topoSort(i, s, vis, adj);

    vector<int> transpose[n+1];
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
            transpose[it].push_back(i);
    }

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!vis[node])
        {
            cout << "SCC: ";
            revdfs(node, vis, transpose);
            cout << endl;
        }
    }
}