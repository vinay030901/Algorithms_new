#include<bits/stdc++.h>
using namespace std;
int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m==0) return -1;
        int n = dungeon[0].size();
        //Initialise dp array and prepare it for boundary cases
        vector<vector<int> > dp(m+1, vector<int> (n+1,0));
        for(int i=0;i<m+1;i++) dp[i][n] = INT_MAX;
        for(int i=0;i<n+1;i++) dp[m][i] = INT_MAX;
        dp[m][n-1] = 1;
        dp[m-1][n] = 1;
        //filling dp subproblems for (m,n) to (0,0)
        int val = 0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                val = min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                dp[i][j] = val<=0?1:val;
            }
        }
        return dp[0][0];
    }
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>p(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
    }
}