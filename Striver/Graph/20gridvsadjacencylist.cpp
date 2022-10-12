/*
representation of graph in matrix and adjacency list is different

in adjacency list: we know the number of adjacent nodes

implementation:
void dfs(int node)
{
    vis[node]=1;
    for(auto it:adj[node])
    if(!vis[it] dfs(it)
}

but in the case of matrix or grid, it is different, we don't know the number of adjacent nodes and therefore we need to
check each and every part of the grid here

void dfs(int x,int y)
{
    vis[x][y]=1;
    if(isValid(x-1,y)) dfs(x-1,y); up
    if(isValid(x+1,y)) dfs(x-1,y); down
    if(isValid(x,y-1)) dfs(x-1,y); left
    if(isValid(x,y+1)) dfs(x-1,y); right
    }

*/
#include <bits/stdc++.h
using namespace std;
int n, f;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[1001][1001];
bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        if (vis[x][y] == 1)
            return false;
    return true;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    cout << x << " " << y << endl;
    for (int i = 0; i < 4; i++)
    if(isValid(x+dx[i],y+dy[i]) dfs(x+dx[i],y+dy[i]);
    // if(isValid(x-1,y)) dfs(x-1,y); //up
    // if(isValid(x+1,y)) dfs(x+1,y); //down
    // if(isValid(x,y-1)) dfs(x,y-1); //left
    // if(isValid(x,y+1)) dfs(x,y+1); //right
}
int main()
{
    int n, m;
    cin >> n >> m;
    dfs(1, 1);
}