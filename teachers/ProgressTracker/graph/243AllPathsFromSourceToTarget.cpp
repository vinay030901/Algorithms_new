/*Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).



Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void dfs(vector<vector<int>> &graph, int st, int target, vector<int> &temp)
{
    if (st == target)
    {
        res.push_back(temp);
        return;
    }
    for (auto i : graph[st])
    {
        temp.push_back(i);
        dfs(graph, i, target, temp);
        temp.pop_back();
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int target = graph.size() - 1;
    vector<int> temp;
    temp.push_back(0);
    dfs(graph, 0, target, temp);
    return res;
}
int main()
{
    // Your code here
    return 0;
}