#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> par, sizes;
void make(int a)
{
    par[a] = a;
    sizes[a] = 1;
}
int findPar(int a)
{
    if (par[a] == a)
        return a;
    return par[a] = findPar(par[a]);
}
void Union(int x, int y)
{
    x = findPar(x);
    y = findPar(y);
    if (x != y)
    {
        if (sizes[y] > sizes[x])
            swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }
}
int longestConsecutive(vector<int> &arr)
{
    for (auto it : arr)
        make(it);
    for (auto it : arr)
        if (par.count(it + 1))
            Union(it, it + 1);
    int mx = 0;
    for (auto it : arr)
        mx = max(mx, sizes[it]);
    return mx;
}