/*
WALK: any random traversal in graph(Vertex and edges can be repeated)
trail: a walk in which no edge is repeated(Vertex can be repeated)

a trail which starts and ends at the same vertex is valled euler circuit.

conditions:
1. start=end
2. every edge must be visited Once

1 - 2 - 3
|  /  \ |
 0      4

above is a euler circuit, to traverse it, we can do 0->1->2->3->4->2->0
we did not repeat any edge here and reached

our graph could be a multicomponent but all the edges must be in a single component.
the other component should have 1 vertex onlu

0 - 1
|  /
2      3   4  so we can start from 0 and reach 0 as 0->1->2->0 3 4

ALL VERTICES SHOULD HAVE EVEN DEGREE

SEMI EULERIAN GRAPH

1 - 2 - 3
|    \  |
0      4


- a euler paht is a pth that visits every edge exactly once. Every circuit is a euler path that starts and ends at the same vertex.

- semi eulerian graph contains:
1. every edge is visited once.
2. start vertex != end vertex

A. exactly 2 vertices must have odd degree(start and end vertex)
B. all other vertices are middle nodes and so we need to enter and exit, the have even degree.
C. all vertices with non zero degree are connected

algorithm to find eulerian, semi eulerian and non eulerian graph

1. connectivity check: check if all edges are present in 1 component only
i. find a node with degree >0
ii.do dfs and mark all nodes in component. check if any node with degree>0 was unvisited
if true-> not eulerian graph
if no node found then

2. count odd degree nodes(using adjacency list)
count=0-> eulerian graph
count=2-> semi eulerian graph
count>2-> not eulerian graph
*/

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis);
    }
}
bool connected_graph(vector<int> adj[], int n)
{
    vector<bool> vis(n, false);
    int node = -1;
    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() > 0)
        {
            node = i;
            break;
        }
    }
    if (node == -1)
        return true; // no start node was found -> no edges present-> it is always eulerian
    dfs(node, adj, vis);
    for (int i = 0; i < n; i++)
        if (vis[i] == false and adj[i].size() > 0)
            return false;
    return true;
}
int find_euler(vector<int> adj[], int n)
{
    if (!connected_graph(adj, n))
        return 0; // multi component graph

    int odd = 0;
    for (int i = 0; i < n; i++)
        if (adj[i].size() & 1)
            odd++;
    if (odd > 2)
        return 0; // more than two elements with odd degree
    return (odd == 0) ? 2 : 1;
}
void findEulerPath(vector<int> adj[], int n)
{
    int ret = find_euler(adj, n);
    if (ret == 0)
        cout << "graph is not a euler graph" << endl;
    else if (ret == 1)
        cout << "graph is semi euler graph" << endl;
    else
        cout << "graph is euler graph" << endl;
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
    findEulerPath(adj, n);
}