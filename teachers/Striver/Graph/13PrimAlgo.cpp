#include <bits/stdc++.h>
using namespace std;

/*
if the graph has exactly n nodes and n-1 edges, then it is called minimum spanning tree
every node should be reachable via every other node
there could be multiple spanning tree, but for minimum spanning tree:

the minimum spanning tree is the one which has the minimum weights
that is, after summing up the edges, the spanning tree which has the minimum cost of edges, it is called minimum spanning tree


algorithm for prim's algo:
we will start from any element and then we will check for the adjacent nodes with the minimum edge weight
we will connect it and move
now we again check for the minimum edge weight, for the both the nodes, the one on which we are now present and the previous one
that will work similarly, we will just check for the minimum edge weight of all the nodes,
and the point when all the nodes are connected, we will stop and this would be our minimum spanning tree

a condition could arise when the minimum edge will connect to already connected, that would create a cycle
so we will take it and take the other minimum

now we will move into the implementation part
*/

void findMinimumSpanningTree(vector<pair<int, int>> adj[], int n)
{
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    // we will initialise key at 0 as 0 and parent of 0 as -1
    key[0] = 0;
    parent[0] = -1;
    // our loop will run for n-1 times because we can only have n-1 vertices
    //  so the the start the node at index 0 has the minimum possible key, and the moment we take the key value, we mark the mst as true
    for (int cnt = 0; cnt < n - 1; cnt++)
    {
        int mn = INT_MAX, pos;
        // first figure minimum value of index and that is not the part of mst,
        // we will store its value and the position at which it is minimum
        for (int i = 0; i < key.size(); i++)
            if (key[i] < mn and mst[i] == false)
            {
                mn = key[i];
                pos = i;
            }
        mst[pos] = true; // we will make that true, that is, it is the part of our spanning tree

        // then we traverse the adjacency matrix of that element and check for the smallest weights, if the weights are lower
        // then we change the value in key and change the parent of the corresponding nodes
        for (auto it : adj[pos])
        {
            int node = it.first, wt = it.second;
            if (mst[node] == false and wt < key[node])
            {
                key[node] = wt;
                parent[node] = pos;
            }
        }
    }
    for (int i = 1; i < n; i++)
        cout << parent[i] << " " << i << "\n";
}

void findMinimumSpanningTree1(vector<pair<int, int>> adj[], int n)
{
    // here we are using priority queue to find the minimum of the graph distances
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn;
    // we will initialise key at 0 as 0 and parent of 0 as -1
    key[0] = 0;
    parent[0] = -1;
    mn.push({0, 0});
    // our loop will run for n-1 times because we can only have n-1 vertices
    //  so the the start the node at index 0 has the minimum possible key, and the moment we take the key value, we mark the mst as true
    for (int cnt = 0; cnt < n - 1; cnt++)
    {
        // first figure minimum value of index and that is not the part of mst,
        // we will store its value and the position at which it is minimum
        int pos = mn.top().second;
        mn.pop();
        mst[pos] = true; // we will make that true, that is, it is the part of our spanning tree

        // then we traverse the adjacency matrix of that element and check for the smallest weights, if the weights are lower
        // then we change the value in key and change the parent of the corresponding nodes
        for (auto it : adj[pos])
        {
            int node = it.first, wt = it.second;
            if (mst[node] == false and wt < key[node])
            {
                key[node] = wt;
                mn.push({key[node], node});
                parent[node] = pos;
            }
        }
    }
    for (int i = 1; i < n; i++)
        cout << parent[i] << " " << i << "\n";
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
    findMinimumSpanningTree1(adj, n);
}