#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool checkCycle(ll node,vector<ll>adj[],vector<ll>&vis,vector<ll>&dfsvis)
{
    vis[node]=1;
    dfsvis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it]){
            if(checkCycle(it,adj,vis,dfsvis)) return true;}
        else if(dfsvis[it]) return true;
    }
    dfsvis[node]=0;
    return false;
}
bool isCycle(ll n,vector<ll>adj[])
{
    vector<ll>vis(n,0),dfsvis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i]){
            if(checkCycle(i,adj,vis,dfsvis))
            return true;
        }
    }
    return false;
}
int main()
{
    ll k;
    cin>>k;
    while(k--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>adj[n+1];
        for(int i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            adj[y].push_back(x);
        }
        if(isCycle(n,adj)) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
