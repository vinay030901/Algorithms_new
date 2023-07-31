#include <bits/stdc++.h>
using namespace std;
bool canFinish(int n, vector<vector<int>> &arr)
{
    vector<int> adj[n], indegree(n), vis(n, 0);
    for (auto it : arr)
    {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!indegree[i])
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
            if (indegree[it] <= 0)
                q.push(it);
        }
    }
    return cnt == n;
}