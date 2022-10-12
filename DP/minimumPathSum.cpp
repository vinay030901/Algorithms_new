#include<bits/stdc++.h>
using namespace std;
int main()
{
    //vector<vector<int>>grid = {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>>grid = {{1,2,3},{4,5,6}};
    int m=grid.size();
    int n=grid[0].size();
    /*int dp[m][n];
    dp[0][0]=grid[0][0];
    for(int i=1;i<m;i++)
    dp[i][0]=grid[i][0]+dp[i-1][0];
    for(int i=1;i<n;i++)
    dp[0][i]=grid[0][i]+dp[0][i-1];
    for(int i=1;i<m;i++)
    for(int j=1;j<n;j++)
    {
        int a=INT_MAX,b=INT_MAX;
        //if(i+1<=m)
            a=dp[i-1][j];
        //if(j+1<=n)
            b=dp[i][j-1];
        dp[i][j]=grid[i][j]+min(a,b);
    }
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
    cout<<dp[i][j]<<" ";
    cout<<endl;}*/
    for(int i=1;i<m;i++)
    grid[i][0]=grid[i][0]+grid[i-1][0];
    for(int i=1;i<n;i++)
    grid[0][i]=grid[0][i]+grid[0][i-1];
    for(int i=1;i<m;i++)
    for(int j=1;j<n;j++)
    grid[i][j]=grid[i][j]+min(grid[i-1][j],grid[i][j-1]);
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
    cout<<grid[i][j]<<" ";
    cout<<endl;}
}
// how many number of permutations exist after that string