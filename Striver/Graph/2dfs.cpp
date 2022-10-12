// in dfs, we explore the as far as we can go in a single child and then we go to the next child
#include <bits/stdc++.h>
using namespace std;
// what we are doing is calling recursion for every node, so instead of getting stored in a queue, which was done in bfs
// here the value are getting stored in a stack
void findDFS(int i, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    vis[i] = 1;
    ans.push_back(i);
    for (auto x : adj[i])
    {
        if (!vis[x])
        {
            findDFS(x, adj, vis, ans);
        }
    }
}
vector<int> dfs(vector<int> adj[], int n)
{
    vector<int> vis(n + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            findDFS(i, adj, vis, ans); // we call the dfs here with necessary data structures
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
    cout << "depth first search: ";
    vector<int> d = dfs(adj, n);
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
}

vector<int>finddfs(int i,vector<int>adj[],vector<int>&vis,vector<int>&ans)
{
    vis[i]=1;
    ans.push_back(i);
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            finddfs(it,adj,vis,ans);
        }
    }
}
vector<int> dfs(vector<int> adj[], int n)
{
    vector<int>vis(n+1,0);
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            finddfs(i,adj,vis,ans);
        }
    }
    return ans;
}