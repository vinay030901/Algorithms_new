#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topoSort(int n, vector<int> adj[])
{
    vector<int> indegree(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
        for (auto it : adj[i])
            indegree[it]++;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);
    int cnt = 0;
    vector<int>topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    reverse(topo.begin(),topo.end());
    if (cnt == n)
        return topo;
    vector<int>a;
    return a;
}
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int>ans;
        //int n=arr.size();
        vector<int>adj[n];
        for(int i=0;i<arr.size();i++)
            adj[arr[i][0]].push_back(arr[i][1]);
        return topoSort(n,adj);
    }
};