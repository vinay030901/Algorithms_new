/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3


Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]*/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &arr, vector<int> &vis, int node)
{
    vis[node] = 1;
    for (int i = 1; i <= arr.size(); i++)
    {
        if (!vis[i] && arr[node - 1][i - 1] == 1)
        {
            dfs(arr, vis, i);
        }
    }
}
int findCircleNum1(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> vis(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(arr, vis, i);
        }
    }
    return ans;
}
vector<int> par;
int findpar(int a)
{
    if (par[a] == -1)
        return a;
    return par[a] = findpar(par[a]);
}
void Union(int a, int b)
{
    a = findpar(a);
    b = findpar(b);
    if (a == b)
        return;
    par[b] = a;
}
int findCircleNum(vector<vector<int>> &arr)
{
    int n = arr.size();
    par = vector<int>(n, -1);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j])
            {
                Union(i, j);
                vis[j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (par[i] == -1)
            ans++;
    return ans;
}

int main()
{
    // Your code here
    return 0;
}