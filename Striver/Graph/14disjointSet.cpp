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

#include<bits/stdc++.h>
using namespace std;
int parent[10000];
int ranking[10000];

void makeSet(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        ranking[i]=0;
    }
}

int findPar(int node){
    if(node==parent[node])
    return node;
    return parent[node]=findPar(parent[node]); // path compression
}

void unions(int u,int v)
{
    u=findPar(u);
    v=findPar(v);
    if(ranking[u]<ranking[v]) parent[u]=v;
    else if(ranking[v]<ranking[u]) parent[v]=u;
    else{
        parent[u]=v;
        ranking[u]++;
    }
}
