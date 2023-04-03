/*we need to count the number of components in the graph*/
#include <bits/stdc++.h
using namespace std;
int n, f;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[1001][1001], arr[1001][1001];
bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    if (vis[x][y] == 1 and arr[i][j])
        return false;
    return true;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    if(isValid(x+dx[i],y+dy[i]) dfs(x+dx[i],y+dy[i]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j] and arr[i][j] == 1)
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
}