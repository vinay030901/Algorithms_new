/* a topo sort is defined as the linear ordering of vertices such that if there is an edge u->v, then u appears before v in
that ordering

topological sort is for directed acyclic graph only*/

#include <bits/stdc++.h>
using namespace std;

/* to find the topo sort, we traverse the graph and find its adjacent nodes
means, we go below in the graph and when the element has no other element to visit, we go back and put the element into the stack
in this way, the child will go into stack first and therefore will be below in the stack
so, afterthat, we will take out the element one by one and return vector*/
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, vis, adj, st);
    st.push(node);
}
vector<int> topoSort(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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
    for (int i = 1; i <= n; i++)
    {
        cout << i;
        for (auto x : adj[i])
            cout << " --> " << x;
        cout << "\n";
    }
    vector<int> topo = topoSort(n, adj);
    for (int i = 0; i < topo.size(); i++)
        cout << topo[i] << " ";
}