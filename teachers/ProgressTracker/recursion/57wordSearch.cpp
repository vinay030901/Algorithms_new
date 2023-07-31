#include <bits/stdc++.h>
using namespace std;
int n, m;
int dis[5] = {-1, 0, 1, 0, -1};
bool check(vector<vector<char>> &arr, int i, int j, string &word, int ind, vector<vector<bool>> &vis)
{
    if (ind >= word.size())
        return true;
    vis[i][j] = true;
    for (int d = 0; d < 4; d++)
    {
        int nx = i + dis[d], ny = j + dis[d + 1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && arr[nx][ny] == word[ind])
        {
            if (check(arr, nx, ny, word, ind + 1, vis))
                return true;
        }
    }
    vis[i][j] = false;
    return false;
}
bool exist(vector<vector<char>> &arr, string word)
{
    n = arr.size();
    m = arr[0].size();
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == word[0])
            {
                vector<vector<bool>> vis(n, vector<bool>(m, 0));
                if (check(arr, i, j, word, 1, vis))
                    return true;
            }
        }
    }
    return false;
}