/* In the mathematical field of graph theory, a bipartite graph (or bigraph) is a graph whose vertices can be divided into
two disjoint and independent sets and , that is every edge connects a vertex in to one in . Vertex sets and. are usually
called the parts of the graph.

in easy words: a birpartite graph can be coloured using two colours and no adjacent nodes will have the same colour

so, a graph is not bipartite, only if, it has a cycle and the no of nodes in that cycle is odd
other than that, the graph is bipartite*/

/* in bfs, we travel to the adjacent nodes first and then we travel to the child of those nodes*/
#include <bits/stdc++.h>
using namespace std;
bool checkBipartitebfs(vector<int> adj[], int n)
{
    vector<int> col(n + 1, -1); // we mark a visited matrix for us
    for (int i = 0; i < n; i++) // this loop would be used, when we don't have a single connected component in our graph
    {
        if (col[i] == -1)
        {
            queue<int> q; // we always use a queue in bfs traversal
            q.push(i);
            col[i] = 1; // mark the element as visited and also mark the colour in it
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto x : adj[node])
                {
                    if (col[x] == -1) // this is an important part, if not done, our graph will be in a cycle and give tle
                    {
                        q.push(x);
                        col[x] = 1 - col[node];
                    }
                    else if (col[x] == col[node]) // if find the element again but it has a different colour,
                        return false;
                }
            }
        }
    }
    return true;
}
// we can also do the same using dfs too
bool dfs(int node, vector<vector<int>> &adj, vector<int> &col)
{
    if (col[node] == -1)
        col[node] = 1;
    for (auto it : adj[node])
    {
        if (col[it] == -1)
        {
            col[it] = 1 - col[node];
            if (dfs(it, adj, col))
                return true;
        }
        else if (col[node] == col[it])
            return true;
    }
    return false;
}
bool isBipartite(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> col(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
            if (dfs(i, adj, col))
                return false;
    }
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
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i;
        for (auto x : adj[i])
            cout << " --> " << x;
        cout << "\n";
    }
    if (checkBipartitebfs(adj, n))
        cout << "graph is bipartite";
    else
        cout << "graph is not bipartite.";
}