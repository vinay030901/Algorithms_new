/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/
// one things important to understand is [0,1] means to take course 0, you have to take course 1
// so course 1 is above course 0 in the graph and the line goes from 1 to 0.
// therefore while creating the adjacency list, we are doing adj[it[1]].push_back(it[0]), and the indegree of it[0] increase

#include <bits/stdc++.h>
using namespace std;
bool canFinish(int n, vector<vector<int>> &arr)
{
    vector<int> adj[n], indegree(n), vis(n, 0);
    for (auto it : arr)
    {
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
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