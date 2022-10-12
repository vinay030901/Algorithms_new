#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&storeddfs){
        storeddfs.push_back(node);
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,storeddfs);
            }
        }
}
vector<int>depthFirstSearch(int V,vector<int>adj[]){
    vector<int>storeddfs;
    vector<int>vis(V+1,0);
    for(int i=1;i<=V;i++)
    if(!vis[i])
    dfs(i,adj,vis,storeddfs);
    return storeddfs;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        cout<<i;
        for(auto x:adj[i])
        {
            cout<<"->"<<x;
        }
        cout<<endl;
    }
    cout<<"depthFirstSearch: ";
    vector<int>dfs=depthFirstSearch(n,adj);
    for(int i=0;i<dfs.size();i++){
        cout<<dfs[i]<<" ";
    }
}