/*A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. For example, there are 3 SCCs in the following graph.

strongly connected components can be thoought as self contained cycle where every vertex can reach the other vertex in that cycle

low link value: the low link value of a node is the smallest node id reachable from that node when doing a dfs(including itself)

and all nodes with the same low link values are together but it depend on the ordering of the graph, this is where tarjan's algo works
it help in proper traversal of graph and find the low link value

new low link condition: to update u's low to v's low, there has to be path from u to v and v must be on the stack
*/

#include <bits/stdc++.h>
using namespace std;
int scc = 0;
stack<int> st;
void dfs(int node, int par, vector<int> &in, vector<int> &low, vector<bool> &vis, int timer, vector<int> adj[], vector<bool> &onstack)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    st.push(node);
    onstack[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] && onstack[it])
        {
            low[it] = min(low[node], in[it]);
        }
        else if (!vis[it])
        {
            dfs(it, node, in, low, vis, timer, adj, onstack); // forward edge
            if (onstack[it])
                low[node] = min(low[node], low[it]);
            // if (low[it] > in[node])
            //     cout << node << " - " << it << " is a bridge" << endl;
        }
    }
    if (in[node] == low[node])
    {
        scc++;
        cout << "SCC #" << scc << endl;
        int u;
        while (1)
        {
            u = st.top();
            st.pop();
            cout << u << " ";
            if (u == node)
                break;
        }
        cout << endl;
    }
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

    // we have two arrays, in and low, in will store the time in which we enter the node,
    // at node 1 the value is zero, and suppose we enter the node 2 next, then the value at node 2 is 1
    // so its obvious that if two nodes are at same path, then the one with lower in time is ancestor of the one with higher
    // low indicates the lowest ancestor or something which can reach directly to the node
    vector<int> in(n + 1, -1), low(n + 1, -1);
    vector<bool> vis(n + 1, 0), onstack(n + 1, 0);
    int timer = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, -1, in, low, vis, timer, adj, onstack);
}