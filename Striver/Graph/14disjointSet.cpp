/*
assume there are multiple components in a graph and we have nodes and we need to check if they belong to the same component
that's where disjoint set data structure is used

so for example we have 7 nodes, at the start all the nodes will be parent of itself

then union 1-2, we combine 1 and 2, and we make 1 as parent
then union 2-3, we attack 2 to 3, as 1 remain parent
union 4-5, assume 4 as parent
union 6-7, combine 6 and 7, 6 is parent
union 5-6, combine them and we have 4 as parent
so if someone ask us does 2 and 7 belong to same component, then we can say no

so we will see the implementation
we will have rank vector with us, all the value of it will be zero
whenever we attack two similar rank guys, we will increase the rank of one of these two
and if the rank of one is smaller, then we will not increasr the rank

we will also do path compression, that is if 7 is parent of 4 and 4 is parent of 3, then we make 7 as parent direcly of 3
*/

#include <bits/stdc++.h>
using namespace std;
class dsu
{
    vector<int> par, rank, size;

public:
    dsu(int n)
    {
        for (int i = 0; i <= n; i++)
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
