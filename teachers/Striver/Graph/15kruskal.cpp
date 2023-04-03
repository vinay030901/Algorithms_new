/*
so kruskal algorithm need knowledge of disjoint set
first of all we will not use the graph, instead we will save the values in a linear data structure and sort them according to weight

1.then we will greedily pickup the elements,
2. check if u an v, that is nodes belong to same component or not,  if they doesn't we will join them
3. if u and v belong to same compoenent, then we will not connect them, or else we will make a cycle

time complexity is O(MLogM)
space complexity: O(N)*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, wt;
    node(int f, int s, int w)
    {
        u = f;
        v = s;
        wt = w;
    }
};
bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector <int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] > rank[v])
        parent[v] = u;
    else if (rank[v] > rank[u])
        parent[u] = v;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edge;
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        edge.push_back({a, b, wt});
    }
    sort(edge.begin(), edge.end(), comp); // we first sort the data structure

    vector<int> parent(n),rank(n,0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int cost=0;
    vector<pair<int,int>>mst;

    for(auto it:edge)
    {
        if(findPar(it.u,parent)!=findPar(it.v,parent)) // if they don't have common component, then we join then
        {
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }
    cout<<"cost is: "<<cost<<endl;
    for(auto it:mst) cout<<it.first<<" - "<<it.second<<endl;
}