#include <bits/stdc++.h>
using namespace std;
vector<int> par, ranks;
int findPar(int a)
{
    if (par[a] == -1)
        return a;
    return par[a] = findPar(par[a]);
}
void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (u == v)
        return;
    if (ranks[u] < ranks[v])
    {
        par[u] = v;
        ranks[v] += ranks[u];
    }
    else
    {
        par[v] = u;
        ranks[u] += ranks[v];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    par = vector<int>(n + 1, -1);
    ranks = vector<int>(n + 1, 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << par[i] << " ";
        if (par[i] == -1)
            ans++;
    }
    cout << ans;
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