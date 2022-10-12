#include <bits/stdc++.h>
using namespace std;
/* the process of this is basic, we will use basic bfs for finding the process
what we do it put the source in the queue and we will use the adjacent nodes of the source for finding the minimum distance

what we will do is traverse throught the adjacent nodes and check if the distance[node]+1<dis[it]-> if it is, it means there is a shorter
path from this node and so, we will update it and put the iterator in the queue for further processing

when the queue is empty, we will return the distance vector*/
vector<int> shortestDistance(vector<int> adj[], int n)
{
    vector<int> dis(n, INT_MAX);
    queue<int> q;
    int source;
    cout << "input the source: ";
    cin >> source;
    dis[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dis[node] + 1 < dis[it])
            {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }
    return dis;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto x : adj[i])
            cout << " --> " << x;
        cout << "\n";
    }
    vector<int> ans = shortestDistance(adj, n);
    for (int i = 0; i < ans.size(); i++)
        cout << i << " " << ans[i] << endl;
}