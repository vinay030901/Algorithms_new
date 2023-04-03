#include <bits/stdc++.h>
using namespace std;

/*so in the approach here, we will use a priority queue, so that the shortest heights will come above and we can process it easily

what we do is first we define a min priority queue, it will be a heap of pair,
we will put the distance as first and later the node, so that we get the min distance first and we process it first

then we make a while loop till the queue is empty, we will, similarly to the last algo
take the distance and node, then compare it with their adjacent nodes
if the distance is lower, then we change the value and we push that in priority queue again

DIJKSTRA COULD WORK FOR BOTH DIRECTED AND UNDIRECTED*/

vector<int> shortestPath(int source, vector<pair<int, int>> adj[], int n)
{
    vector<int> dis(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn;
    dis[source] = 0;
    mn.push({0, source});
    while (!mn.empty())
    {
        int d = mn.top().first;
        int node = mn.top().second;
        mn.pop();
        for (auto it : adj[node])
        {
            if (d + it.second < dis[it.first])
            {
                dis[it.first] = d + it.second;
                mn.push({dis[it.first], it.first});
            }
        }
    }
    return dis;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " --> ";
        for (auto x : adj[i])
            cout << "(" << x.first << " , " << x.second << ") ";
        cout << "\n";
    }
    int source;
    cout << "enter the source: ";
    cin >> source;
    vector<int> ans = shortestPath(source, adj, n);
    for (int i = 0; i < ans.size(); i++)
        cout << i << " " << ans[i] << endl;
}

