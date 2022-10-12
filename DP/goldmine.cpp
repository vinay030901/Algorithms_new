#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>v={{1,2,3,4},{6,7,3,5},{3,5,2,6}};
    int n=v.size();
    int m=v[0].size();
    int dp[n][m];
    for(int j=m-1;j>=0;j--)
    for(int i=n-1;i>=0;i--)
    {
        if(j==m-1){
            dp[i][j]=v[i][j];
        }
        else if(i==0 && n==1)
        dp[i][j]=v[i][j]+dp[i][j+1];
        else if(i==0 && n>1)
        dp[i][j]=v[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
        else if(i==n-1)
        dp[i][j]=v[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
        else
        {
            int c=max(dp[i][j+1],dp[i-1][j+1]);
           dp[i][j]=v[i][j]+max(c,dp[i+1][j+1]); 
        }
    }
    int mx=dp[0][0];
    for(int i=1;i<n;i++)
    if(mx<dp[i][0])
    mx=dp[i][0];
    cout<<mx<<endl;
}