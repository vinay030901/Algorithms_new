#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<pair<int, int> >g[],vector<int>vis,int &mn,int &e)
{
    vis[node]=1;
    for(auto it:g[node]){
        if(vis[it.first]!=1){
        e=it.first;
        mn=min(mn,it.second);
        dfs(it.first,g,vis,mn,e);
    }}
}
int main()
{
    int n,p;
    cin>>n>>p;
    vector<int>a(p+1),b(p+1),in(n+1,0),out(n+1,0);
    vector<int>vis(n+1,0);
    vector<pair<int,int> >g[n+1];
    vector<vector<int>>ans={};
    for(int i=0;i<p;i++)
    {
        int d;
        cin>>a[i]>>b[i]>>d;
        in[b[i]]=1;
        out[a[i]]=1;
        g[a[i]].push_back({b[i],d});
    }
    for(int i=1;i<=n;i++)
    {
        
        if(in[i]==0 && out[i]==1 && vis[i]!=1)
        {
            int node=i;
            int e;
            int mn=INT_MAX;
            dfs(node,g,vis,mn,e);
            ans.push_back({i,e,mn});
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i][0]<<"  "<<ans[i][1]<<"  "<<ans[i][2]<<endl;
    }
}