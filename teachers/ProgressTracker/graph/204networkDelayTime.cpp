/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.



Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1


Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)*/
#include <bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>> &adj, int n, int k)
{
    vector<int> vis(n + 1, 0);
    int ans = 0;
    vector<int> time(n + 1, 1e7), temp;
    time[0] = 0;
    time[k] = 0;
    vis[k] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj.size(); j++)
        {
            if (time[adj[j][0]] + adj[j][2] < time[adj[j][1]])
            {
                vis[adj[j][1]] = 1;
                time[adj[j][1]] = time[adj[j][0]] + adj[j][2];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            return -1;
    return *max_element(time.begin(), time.end());
}
int main()
{
    // Your code here
    return 0;
}