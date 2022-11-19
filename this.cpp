#include <bits/stdc++.h>
using namespace std;
class dsu
{

public:
    vector<int> par, rank, size;
    dsu(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            par.push_back(i);
            rank.push_back(1);
            size.push_back(1);
        }
    }

    int findPar(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = findPar(par[node]); // path compression
    }
    void unionn(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);
        par[v] = u;
    }
    void unionbyparent(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);
        if (rank[u] < rank[v])
            par[u] = v;
        else if (rank[v] < rank[u])
            par[v] = u;
        else
        {
            par[u] = v;
            rank[u]++;
        }
    }
    void unionbysize(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);
        if (u == v)
            return;
        if (size[u] < size[v])
        {
            par[u] = v;
            size[v] += size[u];
        }
        else
        {
            par[v] = u;
            size[u] += size[v];
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    dsu ds(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ds.unionn(a, b);
    }
    int ans = 0;
    cout<<ds.par.size()<<endl;
    for (int i = 1; i <= ds.par.size(); i++){
        cout<<ds.par[i]<<" ";
        if (ds.par[i] == i)
            ans++;
    }
        
    cout << ans << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}