#include <bits/stdc++.h>
using namespace std;

/*
For a general weighted graph, we can calculate single source shortest distances in O(VE) time using Bellman–Ford Algorithm. 
For a graph with no negative weights, we can do better and calculate single source shortest distances in O(E + VLogV) time using 
Dijkstra’s algorithm. Can we do even better for Directed Acyclic Graph (DAG)? We can calculate single source shortest distances in
 O(V+E) time for DAGs. The idea is to use Topological Sorting.
 
so, our first method to find the shortest path in directed acyclic matrix is using topo sort
we will find toposort of our graph, that would be in a stack, now we will 
- take the element one by one and 
- then we will find the adjacent nodes of it and put the sum in distance matrix, we will use similar technique like the shortest path
- we will check if the sum of the weight and distance of parent node is less than distance of adjacent node now, if it is
- we will change the distance, at last we will get the shortest paths vector
*/
void dfs(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
            dfs(it.first, vis, adj, st);
    }
    st.push(node);
}
vector<int> shortestDistance(int source,vector<pair<int, int>> adj[], int n)
{
    // first we calculte the toposort of the elements
    vector<int> vis(n + 1, 0);
    stack<int> s;
    vector<int> topo;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, s);
    }
    
    vector<int>dis(n,INT_MAX);
    dis[source]=0;
    while(!s.empty())
    {
        int node= s.top();
        s.pop();
        if(dis[node]!=INT_MAX)
        {
            for(auto it:adj[node])
            {
                if(dis[node]+it.second<dis[it.first])
                dis[it.first]=dis[node]+it.second;
            }
        }
    }
    return dis;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " --> ";
        for (auto x : adj[i])
            cout << "(" << x.first << " , " << x.second << ") ";
        cout << "\n";
    }
    int source;
    cout<<"enter the source: ";
    cin>>source;
    vector<int> ans = shortestDistance(source,adj, n);
    for (int i = 0; i < ans.size(); i++)
        cout << i << " " << ans[i] << endl;
}