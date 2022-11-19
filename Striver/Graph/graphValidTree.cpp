#include <bits/stdc++.h>
using namespace std;
class Unionfind
{
public:
    int parent[10000], size[10000], components;
    Unionfind(int n)
    {
        components = n;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findpar(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = findpar(parent[a]);
    }
    bool Union(int a, int b)
    {
        a = findpar(a);
        b = findpar(b);
        if (a == b)
            return false;
        if (size[b] > size[a])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        components--;
        return true;
    }
};
bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    Unionfind uf(n);
    for (auto it : edges)
        if (!uf.Union(it[0], it[1]))
            return false;
    return uf.components == 1;
}
int main()
{
}