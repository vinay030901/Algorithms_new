#include <bits/stdc++.h>
using namespace std;
int parent[1000000];
int root(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = root(parent[a]);
}
void connect(int a, int b)
{
    a = root(a);
    b = root(b);
    if (a != b)
    {
        parent[b] = a;
    }
}
void connectedComponents(int n)
{
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(root(parent[i]));
    }
    cout << s.size() - 1 << '\n';
}
void printAnswer(int N, vector<vector<int>>&edges)
{
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        connect(edges[i][0], edges[i][1]);
    }
    connectedComponents(N);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    printAnswer(n, edges);
    return 0;
}