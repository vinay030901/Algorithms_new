#include <bits/stdc++.h>
using namespace std;
int m, n, cnt = 0;
void fun(int i, int j, vector<vector<char>> &arr)
{
    if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == '0')
        return;
    arr[i][j] = '0';
    fun(i - 1, j, arr);
    fun(i + 1, j, arr);
    fun(i, j - 1, arr);
    fun(i, j + 1, arr);
}
int numIslands(vector<vector<char>> &arr)
{
    n = arr.size();
    m = arr[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '1')
            {
                cnt++;
                fun(i, j, arr);
            }
        }
    return cnt;
}