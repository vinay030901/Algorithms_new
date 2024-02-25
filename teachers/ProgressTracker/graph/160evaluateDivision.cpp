/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.



Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation:
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]


Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // https://leetcode.com/problems/evaluate-division/discuss/1993050/C%2B%2B-or-Graph-DFS-or-Daily-LeetCoding-Challenge-April-Day-30
    unordered_map<string, vector<pair<string, double>>> adjlist;
    unordered_map<string, bool> vis;
    double queryans;
    bool dfs(string start, string end, double product)
    {
        if (start == end)
        {
            queryans = product;
            return true;
        }
        vis[start] = true;
        bool tempans = false;
        for (int i = 0; i < adjlist[start].size(); i++)
        {
            if (!vis[adjlist[start][i].first])
                tempans = dfs(adjlist[start][i].first, end, product * adjlist[start][i].second);
            if (tempans)
                break;
        }
        vis[start] = false;
        return tempans;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size(), m = queries.size();
        for (int i = 0; i < n; i++)
        {
            adjlist[equations[i][0]].push_back({equations[i][1], values[i]});
            adjlist[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
            vis[equations[i][0]] = false;
            vis[equations[i][1]] = false;
        }
        vector<double> ans(m);
        for (int i = 0; i < m; i++)
        {
            string start = queries[i][0], end = queries[i][1];
            queryans = 1;
            if (adjlist.find(start) == adjlist.end() || adjlist.find(end) == adjlist.end())
                ans[i] = -1;
            else
            {
                bool found = dfs(start, end, 1);
                if (found)
                    ans[i] = queryans;
                else
                    ans[i] = -1;
            }
        }
        return ans;
    }
};
int main()
{
    // Your code here
    return 0;
}