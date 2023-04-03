#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
    vector<int>adj[n];
    for(int i=0;i<arr.size();i++)
        adj[arr[i][0]].push_back(arr[i][1]);
    vector<int> indegree(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
        for (auto it : adj[i])
            indegree[it]++;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    // we know that if a topological sort is generated, the number of nodes will be equal to n, since topo sort is linear ordering of vertices
   
        if (cnt == n)
        return true;
    return false;
    }
};